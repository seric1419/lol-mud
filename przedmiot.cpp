#include "lol.h"

////////////////////////////////////////////////////////////////////////////////
////////////////////////PRZEMIOT////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
string Przedmiot::getNazwa_przedmiotu()
{
    return nazwa_przedmiotu;
}
void Przedmiot::setNazwa_przedmiotu(string n)
{
    nazwa_przedmiotu=n;
}
int Przedmiot::getSzybkosc()
{
    return szybkosc;
}
void Przedmiot::setSzybkosc(int s)
{
    szybkosc=s;
}
int Przedmiot::getStat_zycie()
{
    return stat_zycie;
}
void Przedmiot::setStat_zycie(int z)
{
    stat_zycie=z;
}
int Przedmiot::getStat_sila()
{
    return stat_sila;
}
void Przedmiot::setStat_sila(int s)
{
    stat_sila=s;
}
int Przedmiot::getStat_moc()
{
    return stat_moc;
}
void Przedmiot::setStat_moc(int m)
{
    stat_moc=m;
}
char Przedmiot::getRodzaj()
{
    return rodzaj;
}
void Przedmiot::setRodzaj(char c)
{
    rodzaj=c;
}
Przedmiot::Przedmiot()
{
    nazwa_przedmiotu="";
}

