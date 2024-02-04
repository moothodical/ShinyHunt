#include "huntdata.h"

HuntData::HuntData(QString pokemonName, QString game, QString method, int odds) :
    pokemonName(pokemonName),
    game(game),
    method(method),
    odds(odds),
    currentEncounters(0)
{

}

QString HuntData::GetPokemonName()
{
    return pokemonName;
}

QString HuntData::GetGame()
{
    return game;
}

QString HuntData::GetMethod()
{
    return method;
}

int HuntData::GetOdds()
{
    return odds;
}

int HuntData::GetCurrentEncounters()
{
    return currentEncounters;
}

void HuntData::Increment(int increment)
{
    currentEncounters += increment;
}
