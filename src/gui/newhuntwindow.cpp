#include "newhuntwindow.h"
#include "ui_newhuntwindow.h"
#include "huntwindow.h"

#include "../data/pokemongame.h"
#include "../data/huntdata.h"

NewHuntWindow::NewHuntWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewHuntWindow)
{
    ui->setupUi(this);
}

NewHuntWindow::~NewHuntWindow()
{
    delete ui;
}

void NewHuntWindow::Populate()
{
    PopulateGameComboBox();
    PopulateMethodComboBox();
    PopulatePokemonComboBox();
}


void NewHuntWindow::PopulatePokemonComboBox()
{
    QStringList pokemonList = PokemonParser::ParsePokemon();
    // populate the combobox with the list
    ui->pokemonComboBox->addItems(pokemonList);


}

void NewHuntWindow::PopulateGameComboBox()
{
    QList<PokemonGame> gameList = PokemonParser::ParseGames();

    for (const PokemonGame& game : gameList)
    {
        ui->gameComboBox->addItem(game.GetName(), QVariant::fromValue(game));
    }
}

void NewHuntWindow::PopulateMethodComboBox()
{
    QStringList methodList;
    methodList.append("Random Encounter");
    methodList.append("Run Away");
    methodList.append("Breeding");
    methodList.append("Soft Resetting");
    methodList.append("Poke Radar");

    ui->methodComboBox->addItems(methodList);
}

void NewHuntWindow::on_gameComboBox_currentIndexChanged(int index)
{
    QVariant selected = ui->gameComboBox->itemData(index);
    PokemonGame selectedGame = selected.value<PokemonGame>();
    ui->oddsSpinBox->setValue(selectedGame.CalculateOdds());
}


void NewHuntWindow::on_newHuntButton_clicked()
{
    QString pokemonName = ui->pokemonComboBox->currentText();
    QString game = ui->gameComboBox->currentText();
    QString method = ui->methodComboBox->currentText();
    int odds = ui->oddsSpinBox->value();

    HuntData huntData(pokemonName, game, method, odds);
    HuntWindow *huntWindow = new HuntWindow(huntData);
    huntWindow->show();
}

