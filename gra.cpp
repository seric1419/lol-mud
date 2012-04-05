#include "lol.h"
////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////INNE///////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

Gra::Gra()
{
    gracz1 = new Gracz("noname");
}

Gracz* Gra::getGracz()
{
    return gracz1;
}
Mapa* Gra::getMapa()
{
    return mapa1;
}
void Gra::setGracz(Gracz* g)
{
    gracz1 = g;
}
void Gra::setMapa(Mapa* m)
{
    mapa1 = m;
}
void Gra::WczytajGre(int p)
{
    if(p==1)
    {
        cin.ignore();
        StartGry(2);
    }
    if(p==2)
    {
        cin.ignore();
        StartGry(3);
    }
}

void Gra::EkranTytulowy()
{
    cout << "\n\n\n\n\n\n\n\n///////////////////////////////////////////////////////////////////////////////\n";
    cout << "/////// ////////    //// ////////////////// ////// // //// //    //////////////\n";
    cout << "/////// /////// //// /// //////////////////  ////  // //// // /// /////////////\n";
    cout << "/////// /////// //// /// ////////////////// / // / // //// // /// /////////////\n";
    cout << "/////// /////// //// /// ////////////////// //  // // //// // /// /////////////\n";
    cout << "///////     ////    ////     ////////////// ////// ///    ///    //////////////\n";
    cout << "///////////////////////////////////////////////////////////////////////////////\n";
    cout << "                                                                    by Seric\n";
    cout << "\n                               Podaj swoj nick:\n                                   ";
}
void Gra::StartGry(int i)
{
    if(i==1)
        mapa1 = new MapaPierwsza();
    if(i==2)
        mapa1 = new MapaDruga();
    if(i==3)
        mapa1 = new MapaTrzecia();
    if(i==0){cout<<"Koniec gry";}
    else{
    PrzygotujMape();
    StartGry(mapa1->Start());
    }
}



void Gra::RozpocznijPodroz()
{
    if(gracz1->getPostep()==0)
        StartGry(1);
    else
        WczytajGre(gracz1->getPostep());
}


void Gra::EkranKoncowy()
{
    cout << "\n\n\n\n\n\n\n\n///////////////////////////////////////////////////////////////////////////////\n";
    cout << "///////////////////////////////////////////////////////////////////////////////\n";
    cout << "///////////////////////////////////////////////////////////////////////////////\n";
    cout << "///////////////////////////////KONIEC GRY!/////////////////////////////////////\n";
    cout << "///////////////////////////////////////////////////////////////////////////////\n";
    cout << "///////////////////////////////////////////////////////////////////////////////\n";
    cout << "///////////////////////////////////////////////////////////////////////////////\n";
}
char* Gra::ZwrocImie()
{  
    char* name= new char[20];
    string sprawdzenie;
    bool blad=0;

    do
    {
        blad=0;
        cin >> sprawdzenie;
        if((int)sprawdzenie.length()>3 && (int)sprawdzenie.length()<21)
        {
            for(int i=0;i<(int)sprawdzenie.length();i++)
            {
                if(sprawdzenie[i]<65 || (sprawdzenie[i]>90 && sprawdzenie[i]<97) || sprawdzenie[i]>122)
                {
                    cout<<sprawdzenie[i]<<endl;
                    blad=1;
                }
            }
        }
        else blad=1;
        if(blad==1)
            cout << "Podales zle imie! Imie musi posiadac 4-20 znakow! \nUwaga! Imie sklada sie tylko z liter duzych i malych!"<<endl;
    }while(blad==1);
    strcpy(name,sprawdzenie.c_str());
    return name;
}
int Gra::IloscPrzedmiotow(char * nazwa_pliku)
{
    int i;
    fstream plik_odczyt(nazwa_pliku, ios::in);
    if( plik_odczyt.good())
    {
        plik_odczyt >> i;
        plik_odczyt.close();
        return i;
    } else
    {
        cout<< "Nie znaleziono pliku z przedmiotami!"<<endl;
        return 0;
    }
}
void Gra::PokazBazePrzedmiotow(Przedmiot* p, int ilosc)
{
    for(int i=0;i<ilosc;i++)
    {
        cout << p[i].getNazwa_przedmiotu() << " " << p[i].getStat_zycie() << " " << p[i].getStat_sila() << " " << p[i].getStat_moc()<< " " << p[i].getSzybkosc() << endl;
    }
}
int Gra::IloscPotworow(char * nazwa_pliku)
{
    int i;
    fstream plik_odczyt(nazwa_pliku, ios::in);
    if( plik_odczyt.good())
    {
        plik_odczyt >> i;
        plik_odczyt.close();
        return i;
    } else
    {
        cout<< "Nie znaleziono pliku z potworami!"<<endl;
        return 0;
    }
}
void Gra::PokazBazePotworow(Potwor* p, int ilosc)
{
    for(int i=0;i<ilosc;i++)
    {
        cout << p[i].getNazwa_potwora() << " " << p[i].getStat_zycie() << " " << p[i].getStat_sila() << " " << p[i].getStat_moc()<<" "<< p[i].getIlosc_doswiadczenia()<<endl;
    }
}
void Gra::PrzygotujGre()
{
    EkranTytulowy();
    PrzygotujGracza();
    RozpocznijPodroz();
}
void Gra::PrzygotujGracza()
{
    gracz1->WczytajPostac(ZwrocImie());
}
void Gra::PrzygotujMape()
{
    mapa1->setGracz(gracz1);
    fstream plik_odczyt("nazwy_plikow.txt", ios::in);
    if( plik_odczyt.good())
    {
        char* zmienna =new char[20];
        plik_odczyt >> zmienna;
        mapa1->setIlosc_przedmiotow(IloscPrzedmiotow(zmienna));
        mapa1->setBaza_przedmiotow(zmienna);
        //PokazBazePrzedmiotow(aktualna_mapa->getBaza_przedmiotow(), aktualna_mapa->getIlosc_przedmiotow());
        plik_odczyt >> zmienna;
        mapa1->setIlosc_potworow(IloscPotworow(zmienna));
        mapa1->setBaza_potworow(zmienna);
        //PokazBazePotworow(aktualna_mapa->getBaza_potworow(), aktualna_mapa->getIlosc_potworow());
        plik_odczyt.close();
    }else cout<< "Nie znaleziono pliku z nazwami plikow!"<<endl;
}

