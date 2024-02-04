#include "pokemonparser.h"

QStringList PokemonParser::ParsePokemon()
{
    QStringList pokemonList{};

    QJsonDocument jsonDocument = GetJson("pokedex.json");
    // qDebug() << "Json data successfully parsed" << jsonDocument;

    QJsonArray jsonArray = jsonDocument.array();

    for (const QJsonValue &jsonValue : jsonArray)
    {
        QJsonObject jsonObject = jsonValue.toObject();
        QJsonObject pokemonNameObj = jsonObject.value("name").toObject();
        QString englishName = pokemonNameObj.value("english").toString();
        pokemonList.append(englishName);
    }

    return pokemonList;
}

QList<PokemonGame> PokemonParser::ParseGames()
{
    QList<PokemonGame> gamesList{};

    QJsonDocument jsonDocument = GetJson("games.json");
    qDebug() << "Json data successfully parsed" << jsonDocument;

    QJsonValue test = jsonDocument.object();
    QJsonArray jsonArray = test["pokemonGames"].toArray();

    for (const QJsonValue &jsonValue : jsonArray)
    {
        QJsonObject jsonObject = jsonValue.toObject();
        QString gameName = jsonObject.value("name").toString();
        int generation = jsonObject.value("generation").toInt();
        PokemonGame game(gameName, generation);
        gamesList.append(game);
    }

    return gamesList;
}

QJsonDocument PokemonParser::GetJson(QString fileName)
{
    QString basePath(":/pokemon/pokemon/");
    QString file(basePath + fileName);
    QFile jsonFile(file);

    if (!jsonFile.open(QIODevice::ReadOnly))
    {
        qDebug() << "Failed to open pokemon.json file";
    }

    QByteArray jsonData = jsonFile.readAll();
    jsonFile.close();

    return QJsonDocument::fromJson(jsonData);
}
