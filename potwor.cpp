#include "lol.h"
////////////////////////////////////////////////////////////////////////////////
//////////////////////////////POTWORY///////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
string Potwor::getNazwa_potwora()
{
    return nazwa_potwora;
}
void Potwor::setNazwa_potwora(string n)
{
    nazwa_potwora=n;
}
int Potwor::getStat_zycie()
{
    return stat_zycie;
}
void Potwor::setStat_zycie(int z)
{
    stat_zycie=z;
}
int Potwor::getStat_sila()
{
    return stat_sila;
}
void Potwor::setStat_sila(int s)
{
    stat_sila=s;
}
int Potwor::getStat_moc()
{
    return stat_moc;
}
void Potwor::setStat_moc(int m)
{
    stat_moc=m;
}
int Potwor::getSzansa_item()
{
    return szansa_item;
}
void Potwor::setSzansa_item(int s)
{
    szansa_item=s;
}
int Potwor::getIlosc_zlota()
{
    return ilosc_zlota;
}
void Potwor::setIlosc_zlota(int i)
{
    ilosc_zlota=i;
}

int Potwor::getAktualne_zycie()
{
    return aktualne_zycie;
}
void Potwor::setAktualne_zycie(int a)
{
    aktualne_zycie=a;
}
int Potwor::getIlosc_doswiadczenia()
{
    return ilosc_doswiadczenia;
}
void Potwor::setIlosc_doswiadczenia(int i)
{
    ilosc_doswiadczenia=i;
}
