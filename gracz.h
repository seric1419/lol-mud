#ifndef gracz_hpp
#define gracz_hpp

////////////////////////////////////////////////////////////////////////////////
//////////////////////////////GRACZ/////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
class Gracz
{
private:
    int postep;
    char *nazwa;
    int poziom;
    int max_doswiadczenie;
    int doswiadczenie;
    int aktualne_zycie;
    int zycie;
    int sila;
    int moc;
    int szybkosc;
    int zloto;
    int ilosc_przedmiotow;
    Charakter charakter;
    Ekwipunek ekwipunek; // obecnie zalozony ekwipunek
public:
    void setPostep(int);
    int getPostep();
    char* getNazwa();
    void setNazwa(char*);
    int getPoziom();
    void setPoziom(int);
    int getMax_doswiadczenie();
    void setMax_doswiadczenie(int);
    int getDoswiadczenie();
    void setDoswiadczenie(int);
    int getAktualne_zycie();
    void setAktualne_zycie(int);
    int getZycie();
    void setZycie(int);
    int getSila();
    void setSila(int);
    int getMoc();
    void setMoc(int);
    int getSzybkosc();
    void setSzybkosc(int);
    int getZloto();
    void setZloto(int);
    int getIlosc_przedmiotow();
    void setIlosc_przedmiotow(int);
    Charakter getCharakter();
    void setCharakter(Charakter);

    Gracz(char*); //tworzy nowego gracza o podanej nazwie
    void ZalozEkwipunek(Przedmiot*); //zaklada ekwipunek i jednoczesnie zdejmuje stary
    void ZdejmijEkwipunek(Przedmiot*); // zdejmuje ekwipunek Gracza
    void WczytajPostac(char*); // Wczytuje postac z pliku
    void ZapiszPostac(); // zapisuje postac do pliku
    void PokazStatystyki(); // pokazuje statystyki gracza
    void PokazEkwipunek(); // pokazuje aktualny ekwipunek gracza
    void SmiercGracza(); // operacje w czasie smierci gracza
    void Lvlup(); // podniesienie poziomu gracza
    void WyleczGracza(); // leczy gracza do max punktow zycia
};

#endif
