#ifndef potwor_hpp
#define potwor_hpp
////////////////////////////////////////////////////////////////////////////////
//////////////////////////////POTWORY///////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
class Potwor
{
private:
    string nazwa_potwora;
    int aktualne_zycie;
    int stat_zycie;
    int stat_sila;
    int stat_moc;
    int szansa_item;
    int ilosc_zlota;
    int ilosc_doswiadczenia;
public:
    string getNazwa_potwora();
    void setNazwa_potwora(string);
    int getAktualne_zycie();
    void setAktualne_zycie(int);
    int getStat_zycie();
    void setStat_zycie(int);
    int getStat_sila();
    void setStat_sila(int);
    int getStat_moc();
    void setStat_moc(int);
    int getSzansa_item();
    void setSzansa_item(int);
    int getIlosc_zlota();
    void setIlosc_zlota(int);
    int getIlosc_doswiadczenia();
    void setIlosc_doswiadczenia(int);
};
#endif
