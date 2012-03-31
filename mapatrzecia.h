#ifndef MAPATRZECIA_H
#define MAPATRZECIA_H

#include "lol.h"
class MapaTrzecia : public Mapa
{
public:
    MapaTrzecia();
    MapaTrzecia(Gracz*);
    int Start();
};

#endif // MAPATRZECIA_H
