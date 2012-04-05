#include "lol.h"
////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////MAPA///////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
Potwor* Mapa::getBaza_potworow()
{
    return baza_potworow;
}
void Mapa::setBaza_potworow(char* nazwa_pliku)
{
    baza_potworow= new Potwor[ilosc_potworow];
    fstream plik_odczyt(nazwa_pliku, ios::in);
    if( plik_odczyt.good())
    {
        string tekst;
        int liczba;
        plik_odczyt >>liczba; // POMIJAMY pierwsza liczbe, ktora jest liczba potworow
        for(int i=0;i<ilosc_potworow;i++)
        {
            plik_odczyt >> tekst;
            baza_potworow[i].setNazwa_potwora(tekst);
            plik_odczyt >> liczba;
            baza_potworow[i].setStat_zycie(liczba);
            baza_potworow[i].setAktualne_zycie(liczba);
            plik_odczyt >> liczba;
            baza_potworow[i].setStat_sila(liczba);
            plik_odczyt >> liczba;
            baza_potworow[i].setStat_moc(liczba);
            plik_odczyt >> liczba;
            baza_potworow[i].setSzansa_item(liczba);
            plik_odczyt >> liczba;
            baza_potworow[i].setIlosc_zlota(liczba);
            plik_odczyt >> liczba;
            baza_potworow[i].setIlosc_doswiadczenia(liczba);
        }
        plik_odczyt.close();
    } else cout << "Nie znaleziono pliku z potworami!"<<endl;
}
int Mapa::getIlosc_potworow()
{
    return ilosc_potworow;
}
void Mapa::setIlosc_potworow(int i)
{
    ilosc_potworow=i;
}
Przedmiot* Mapa::getBaza_przedmiotow()
{
    return baza_przedmiotow;
}
void Mapa::setBaza_przedmiotow(char* nazwa_pliku)
{
    baza_przedmiotow= new Przedmiot[ilosc_przedmiotow];
    fstream plik_odczyt(nazwa_pliku, ios::in);
    if( plik_odczyt.good())
    {
        string tekst;
        int liczba;
        char c;
        plik_odczyt >>liczba; // POMIJAMY pierwsza liczbe, ktora jest liczba przedmiotow
        for(int i=0;i<ilosc_przedmiotow;i++)
        {
            plik_odczyt >> tekst;
            baza_przedmiotow[i].setNazwa_przedmiotu(tekst);
            plik_odczyt >> liczba;
            baza_przedmiotow[i].setSzybkosc(liczba);
            plik_odczyt >> liczba;
            baza_przedmiotow[i].setStat_zycie(liczba);
            plik_odczyt >> liczba;
            baza_przedmiotow[i].setStat_sila(liczba);
            plik_odczyt >> liczba;
            baza_przedmiotow[i].setStat_moc(liczba);
            plik_odczyt >> c;
            baza_przedmiotow[i].setRodzaj(c);
        }
        plik_odczyt.close();
    } else cout<< "Nie znaleziono pliku z przedmiotami!"<<endl;
}
int Mapa::getIlosc_przedmiotow()
{
    return ilosc_przedmiotow;
}
void Mapa::setIlosc_przedmiotow(int i)
{
    ilosc_przedmiotow=i;
}
Przedmiot* Mapa::Losujprzedmiot()
{
    srand ( time(NULL) );
    int i=rand()%ilosc_przedmiotow;
    Przedmiot* p = new Przedmiot();

    p->setNazwa_przedmiotu(baza_przedmiotow[i].getNazwa_przedmiotu());
    p->setSzybkosc(baza_przedmiotow[i].getSzybkosc());
    p->setStat_zycie(baza_przedmiotow[i].getStat_zycie());
    p->setStat_sila(baza_przedmiotow[i].getStat_sila());
    p->setStat_moc(baza_przedmiotow[i].getStat_moc());
    p->setRodzaj(baza_przedmiotow[i].getRodzaj());
    return p;
}
Przedmiot* Mapa::Losujprzedmiot(int a)
{
    srand ( time(NULL) );
    int i=rand()%(ilosc_przedmiotow-a);
    Przedmiot* p = new Przedmiot();

    p->setNazwa_przedmiotu(baza_przedmiotow[i].getNazwa_przedmiotu());
    p->setSzybkosc(baza_przedmiotow[i].getSzybkosc());
    p->setStat_zycie(baza_przedmiotow[i].getStat_zycie());
    p->setStat_sila(baza_przedmiotow[i].getStat_sila());
    p->setStat_moc(baza_przedmiotow[i].getStat_moc());
    p->setRodzaj(baza_przedmiotow[i].getRodzaj());
    return p;
}
Potwor* Mapa::Losujpotwora()
{
    srand ( time(NULL) );
    int i=rand()%ilosc_potworow;
    Potwor* p = new Potwor();

    p->setNazwa_potwora(baza_potworow[i].getNazwa_potwora());
    p->setAktualne_zycie(baza_potworow[i].getStat_zycie());
    p->setStat_zycie(baza_potworow[i].getStat_zycie());
    p->setStat_sila(baza_potworow[i].getStat_sila());
    p->setStat_moc(baza_potworow[i].getStat_moc());
    p->setSzansa_item(baza_potworow[i].getSzansa_item());
    p->setIlosc_zlota(baza_potworow[i].getIlosc_zlota());
    p->setIlosc_doswiadczenia(baza_potworow[i].getIlosc_doswiadczenia());

    return p;
}
void Mapa::SilaPotworow(int a)
{
    if(a==2)
    {
        setBaza_potworow("potwory2.txt");
    }
    else if(a==3)
    {
        setBaza_potworow("potwory3.txt");
    }
    else if(a==4)
    {
        setBaza_potworow("potwory4.txt");
    }
    else if(a>4)
    {
        setBaza_potworow("bosowie.txt");
    }
    else cout<< "Blad wczytywania sily stworow"<<endl;
}
void Mapa::PokazWalczacych(Potwor* p)
{
    cout << "Gracz: " << getGracz()->getNazwa() << " HP: " << getGracz()->getAktualne_zycie() << endl;
    cout << "Potwor: " << p->getNazwa_potwora() << " HP: " << p->getAktualne_zycie() << endl;
    cout << endl;
}
Gracz* Mapa::getGracz()
{
    return gracz1;
}
void Mapa::setGracz(Gracz* g)
{
    gracz1=g;
}
Mapa::~Mapa()
{

}





