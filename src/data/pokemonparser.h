#ifndef POKEMONPARSER_H
#define POKEMONPARSER_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QString>
#include <QDir>
#include <QResource>
#include <QTextStream>
#include <QByteArray>
#include <QList>
#include <QStringList>

#include "pokemongame.h"

class PokemonParser
{
private:
    static QJsonDocument GetJson(QString fileName);
public:
    static QStringList ParsePokemon();
    static QList<PokemonGame> ParseGames();
};

#endif // POKEMONPARSER_H
