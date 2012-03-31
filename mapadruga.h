#ifndef MAPADRUGA_H
#define MAPADRUGA_H
#include "lol.h"
class MapaDruga : public Mapa
{
public:
    MapaDruga();
    MapaDruga(Gracz*);
    int Start();
    void Arena(); // gracz wchodzi na arene
    void Karczma(); // gracz wchodzi do karczmy
    void Kupowanie(); // kupowanie w sklepie
    void Krol(); // rozmowa z krolem
    void Sklep(); // gracz wchodzi do sklepu
    void Walka();  // gracz walczy z przeciwnikiem

};

#endif // MAPADRUGA_H
