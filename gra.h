#ifndef gra_hpp
#define gra_hpp
////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////INNE///////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
class Gra
{
private:
    Gracz* gracz1;
    Mapa* mapa1;
public:
    void setGracz(Gracz*);
    Gracz* getGracz();
    void setMapa(Mapa*);
    Mapa* getMapa();

    void EkranTytulowy();
    char* ZwrocImie();
    int IloscPrzedmiotow(char * nazwa_pliku);
    void PokazBazePrzedmiotow(Przedmiot* p, int ilosc);
    int IloscPotworow(char * nazwa_pliku);
    void PokazBazePotworow(Potwor* p, int ilosc);
    void PrzygotujGre();
    void PrzygotujGracza();
    void PrzygotujMape();
    void StartGry(int);
    void EkranKoncowy(); // koniec
    void WczytajGre(int); // wczytuje gre
    void RozpocznijPodroz();
    Gra();
};
#endif
