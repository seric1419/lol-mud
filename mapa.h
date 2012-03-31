#ifndef mapa_hpp
#define mapa_hpp
////////////////////////////////////////////////////////////////////////////////
////////////////////////////MAPY////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
class Mapa
{
private:
    Gracz* gracz1;
    Potwor* baza_potworow;
    int ilosc_potworow;
    Przedmiot* baza_przedmiotow;
    int ilosc_przedmiotow;
public:
    void setGracz(Gracz*);
    Gracz* getGracz();
    void setBaza_potworow(char*);
    Potwor* getBaza_potworow();
    void setIlosc_potworow(int);
    int getIlosc_potworow();
    void SilaPotworow(int); // zwieksza poziom potworow
    void setBaza_przedmiotow(char*);
    Przedmiot* getBaza_przedmiotow();
    void setIlosc_przedmiotow(int);
    int getIlosc_przedmiotow();
    virtual int Start(){};
    Przedmiot* Losujprzedmiot(); // zwraca losowy przedmiot
    Przedmiot* Losujprzedmiot(int); // zwraca losowy przedmiot(uzywane przy wczytowaniu kilka razy)
    Potwor* Losujpotwora(); // zwraca losowe potwora z bazy
    void PokazWalczacych(Potwor*);
    ~Mapa();

};

#endif
