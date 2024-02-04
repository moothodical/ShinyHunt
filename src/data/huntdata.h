#ifndef HUNTDATA_H
#define HUNTDATA_H

#include <QString>

class HuntData
{
private:
    QString pokemonName;
    QString game;
    QString method;
    int odds;
    int currentEncounters;
public:
    HuntData(QString pokemonName, QString game, QString method, int odds);
    QString GetPokemonName();
    QString GetGame();
    QString GetMethod();
    int GetOdds();
    int GetCurrentEncounters();
    void Increment(int increment);
};

#endif // HUNTDATA_H
