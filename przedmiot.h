#ifndef przedmioty_hpp
#define przedmioty_hpp
////////////////////////////////////////////////////////////////////////////////
////////////////////////PRZEDMIOT///////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
class Przedmiot
{
private:
    string nazwa_przedmiotu;
    int szybkosc;
    int stat_zycie;
    int stat_sila;
    int stat_moc;
    char rodzaj;
public:
    string getNazwa_przedmiotu();
    void setNazwa_przedmiotu(string);
    int getSzybkosc();
    void setSzybkosc(int);
    int getStat_zycie();
    void setStat_zycie(int);
    int getStat_sila();
    void setStat_sila(int);
    int getStat_moc();
    void setStat_moc(int);
    char getRodzaj();
    void setRodzaj(char);

    Przedmiot();
};
#endif
