#include "pokemongame.h"

PokemonGame::PokemonGame() {}

PokemonGame::PokemonGame(const QString& name, int generation)
    : name(name), generation(generation) { }

QString PokemonGame::GetName() const
{
    return name;
}

int PokemonGame::GetGeneration()
{
    return generation;
}

int PokemonGame::CalculateOdds()
{
    return generation > 5 ? 4096 : 8192;
}
