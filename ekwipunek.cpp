#include "lol.h"

////////////////////////////////////////////////////////////////////////////////
////////////////////////EKWIPUNEK///////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
Przedmiot* Ekwipunek::getPancerz()
{
    return pancerz;
}
void Ekwipunek::setPancerz(Przedmiot* p)
{
    pancerz =p;
}
Przedmiot* Ekwipunek::getNogi()
{
    return nogi;
}
void Ekwipunek::setNogi(Przedmiot* n)
{
    nogi=n;
}
Przedmiot* Ekwipunek::getBron()
{
    return bron;
}
void Ekwipunek::setBron(Przedmiot* b)
{
    bron=b;
}
Ekwipunek::Ekwipunek()
{
    pancerz= new Przedmiot();
    nogi= new Przedmiot();
    bron = new Przedmiot();
}
