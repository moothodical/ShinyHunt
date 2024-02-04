#ifndef POKEMONGAME_H
#define POKEMONGAME_H

#include <QString>

class PokemonGame
{
private:
    QString name;
    int generation;

public:
    PokemonGame();
    PokemonGame(const QString& name, int generation);
    QString GetName() const;
    int GetGeneration();
    int CalculateOdds();
};

#endif // POKEMONGAME_H
