#ifndef MAPAPIERWSZA_H
#define MAPAPIERWSZA_H

#include "lol.h"
class MapaPierwsza : public Mapa
{
public:
    MapaPierwsza(Gracz* g);
    MapaPierwsza();
    int Start();
};

#endif // MAPAPIERWSZA_H
