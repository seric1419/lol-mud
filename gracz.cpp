#include "lol.h"
////////////////////////////////////////////////////////////////////////////////
/////////////////////////////GRACZ//////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void Gracz::setPostep(int i)
{
    postep=i;
}
int Gracz::getPostep()
{
    return postep;
}
char* Gracz::getNazwa()
{
    return nazwa;
}
void Gracz::setNazwa(char* n)
{
    nazwa = n;
}
int Gracz::getPoziom()
{
    return poziom;
}
void Gracz::setPoziom(int p)
{
    poziom = p;
}
int Gracz::getDoswiadczenie()
{
    return doswiadczenie;
}
void Gracz::setDoswiadczenie(int d)
{
    doswiadczenie =d;
}
int Gracz::getMax_doswiadczenie()
{
    return max_doswiadczenie;
}
void Gracz::setMax_doswiadczenie(int m)
{
    max_doswiadczenie=m;
}
int Gracz::getAktualne_zycie() 
{
    return aktualne_zycie;
}
void Gracz::setAktualne_zycie(int a)
{
    aktualne_zycie=a;
}
int Gracz::getZycie()
{
    return zycie;
}
void Gracz::setZycie(int z)
{
    zycie =z;
}
int Gracz::getSila()
{
    return sila;
}
void Gracz::setSila(int s)
{
    sila =s;
}
int Gracz::getMoc()
{
    return moc;
}
void Gracz::setMoc(int m)
{
    moc = m;
}
int Gracz::getSzybkosc()
{
    return szybkosc;
}
void Gracz::setSzybkosc(int s)
{
    szybkosc=s;
}
int Gracz::getZloto()
{
    return zloto;
}
void Gracz::setZloto(int z)
{
    zloto = z;
}
int Gracz::getIlosc_przedmiotow()
{
    return ilosc_przedmiotow;
}
void Gracz::setIlosc_przedmiotow(int i)
{
    ilosc_przedmiotow =i;
}
Charakter Gracz::getCharakter()
{
    return charakter;
}
void Gracz::setCharakter(Charakter c)
{
    charakter = c;
}

Gracz::Gracz(char* naz)
{
    setNazwa(naz);
    setPostep(0);
    setPoziom(1);
    setDoswiadczenie(0);
    setMax_doswiadczenie(100);
    setAktualne_zycie(100);
    setZycie(100);
    setSila(10);
    setMoc(10);
    setSzybkosc(20);
    setZloto(10);
    setIlosc_przedmiotow(0);
    setCharakter(neutralny);
}
void Gracz::WczytajPostac(char* naz)
{

    fstream plik_odczyt(naz, ios::in);
    if( plik_odczyt.good())
    {
        char znak;
        char *znaki = new char[20];
        string napis;
        int liczba;
        plik_odczyt >> znaki;
        setNazwa(znaki);
        plik_odczyt >> liczba;
        setPostep(liczba);
        plik_odczyt >> liczba;
        setPoziom(liczba);
        plik_odczyt >> liczba;
        setDoswiadczenie(liczba);
        plik_odczyt >> liczba;
        setMax_doswiadczenie(liczba);
        plik_odczyt >> liczba;
        setZycie(liczba);
        plik_odczyt >> liczba;
        setSila(liczba);
        plik_odczyt >> liczba;
        setMoc(liczba);
        plik_odczyt >> liczba;
        setSzybkosc(liczba);
        plik_odczyt >> liczba;
        setZloto(liczba);
        plik_odczyt >> liczba;
        setIlosc_przedmiotow(liczba);
        plik_odczyt >> napis;
        if(napis=="n")
            setCharakter(neutralny);
        else if(napis=="d")
            setCharakter(dobry);
        else if(napis=="z")
            setCharakter(zly);
        else
            cout << "BLAD! NIEUDANA PROBA ODCZYTU CHARAKTERU";
        plik_odczyt >> napis;
        if(napis!="brak")
        {
            ekwipunek.getBron()->setNazwa_przedmiotu(napis);
            plik_odczyt >> znak;
            ekwipunek.getBron()->setRodzaj(znak);
            plik_odczyt >> liczba;
            ekwipunek.getBron()->setStat_moc(liczba);
            plik_odczyt >> liczba;
            ekwipunek.getBron()->setStat_sila(liczba);
            plik_odczyt >> liczba;
            ekwipunek.getBron()->setStat_zycie(liczba);
            plik_odczyt >> liczba;
            ekwipunek.getBron()->setSzybkosc(liczba);
        }
        plik_odczyt >> napis;
        if(napis!="brak")
        {
            ekwipunek.getNogi()->setNazwa_przedmiotu(napis);
            plik_odczyt >> znak;
            ekwipunek.getNogi()->setRodzaj(znak);
            plik_odczyt >> liczba;
            ekwipunek.getNogi()->setStat_moc(liczba);
            plik_odczyt >> liczba;
            ekwipunek.getNogi()->setStat_sila(liczba);
            plik_odczyt >> liczba;
            ekwipunek.getNogi()->setStat_zycie(liczba);
            plik_odczyt >> liczba;
            ekwipunek.getNogi()->setSzybkosc(liczba);
        }
        plik_odczyt >> napis;
        if(napis!="brak")
        {
            ekwipunek.getPancerz()->setNazwa_przedmiotu(napis);
            plik_odczyt >> znak;
            ekwipunek.getPancerz()->setRodzaj(znak);
            plik_odczyt >> liczba;
            ekwipunek.getPancerz()->setStat_moc(liczba);
            plik_odczyt >> liczba;
            ekwipunek.getPancerz()->setStat_sila(liczba);
            plik_odczyt >> liczba;
            ekwipunek.getPancerz()->setStat_zycie(liczba);
            plik_odczyt >> liczba;
            ekwipunek.getPancerz()->setSzybkosc(liczba);
        }
        plik_odczyt.close();
    } else nazwa=naz;
}
void Gracz::ZapiszPostac()
{
    cout << "Zapisac gre? "<<endl;
    string odp;
    cin >> odp;
    if(odp=="tak")
    {
        fstream plik_zapis( nazwa, ios::out);
        if( plik_zapis.good())
        {
            plik_zapis << getNazwa() <<endl;
            plik_zapis << getPostep() <<endl;
            plik_zapis << getPoziom() <<endl;
            plik_zapis << getDoswiadczenie() <<endl;
            plik_zapis << getMax_doswiadczenie() <<endl;
            plik_zapis << getZycie() <<endl;
            plik_zapis << getSila() <<endl;
            plik_zapis << getMoc() <<endl;
            plik_zapis << getSzybkosc() << endl;
            plik_zapis << getZloto() <<endl;
            plik_zapis << getIlosc_przedmiotow() << endl;
            if(getCharakter() ==neutralny)
                plik_zapis << "n" << endl;
            if(getCharakter() ==dobry)
                plik_zapis << "d" << endl;
            if(getCharakter() ==zly)
                plik_zapis << "z" << endl;
            if(ekwipunek.getBron()->getNazwa_przedmiotu() != "")
            {
                plik_zapis << ekwipunek.getBron()->getNazwa_przedmiotu() << endl;
                plik_zapis << ekwipunek.getBron()->getRodzaj() << endl;
                plik_zapis << ekwipunek.getBron()->getStat_moc() << endl;
                plik_zapis << ekwipunek.getBron()->getStat_sila() << endl;
                plik_zapis << ekwipunek.getBron()->getStat_zycie() << endl;
                plik_zapis << ekwipunek.getBron()->getSzybkosc() << endl;
            }
            else plik_zapis << "brak" <<endl;
            if(ekwipunek.getNogi()->getNazwa_przedmiotu() != "")
            {
                plik_zapis << ekwipunek.getNogi()->getNazwa_przedmiotu()<<endl;
                plik_zapis << ekwipunek.getNogi()->getRodzaj()<<endl;
                plik_zapis << ekwipunek.getNogi()->getStat_moc()<<endl;
                plik_zapis << ekwipunek.getNogi()->getStat_sila()<<endl;
                plik_zapis << ekwipunek.getNogi()->getStat_zycie()<<endl;
                plik_zapis << ekwipunek.getNogi()->getSzybkosc()<< endl;
            } else plik_zapis << "brak" <<endl;
            if(ekwipunek.getPancerz()->getNazwa_przedmiotu() != "")
            {
                plik_zapis << ekwipunek.getPancerz()->getNazwa_przedmiotu() <<endl;
                plik_zapis << ekwipunek.getPancerz()->getRodzaj()<< endl;
                plik_zapis << ekwipunek.getPancerz()->getStat_moc()<<endl;
                plik_zapis << ekwipunek.getPancerz()->getStat_sila()<<endl;
                plik_zapis << ekwipunek.getPancerz()->getStat_zycie()<<endl;
                plik_zapis << ekwipunek.getPancerz()->getSzybkosc()<<endl;
                cout<<"Zapisywanie postaci zakonczone pomyslnie!"<<endl;
            } else plik_zapis << "brak" <<endl;
        }else cout << "Nie dalo sie zapisac postaci!" << endl;
    }else if(odp=="nie") cout <<"\n";
    else cout << "Nieprawidlowe polecenie! Wpisz \"tak\" lub \"nie\"" <<endl;

}
void Gracz::PokazStatystyki()
{
    cout << "Nazwa gracza: " << getNazwa() <<endl;
    cout << "Postep: " <<  getPostep() << endl;
    cout << "Poziom: " << getPoziom() <<endl;
    cout << "Doswiadczenie: " << getDoswiadczenie() <<endl;
    cout << "Max doswiadczenie: " << getMax_doswiadczenie() <<endl;
    cout << "Aktualne zycie: " << getAktualne_zycie() <<endl;
    cout << "Max zycie: " << getZycie() <<endl;
    cout << "Sila: " <<getSila() <<endl;
    cout << "Moc: " << getMoc() <<endl;
    cout << "Szybkosc: " << getSzybkosc() << endl;
    cout << "Ilosc zlota: " << getZloto() <<endl;
    if(getCharakter() ==neutralny)
        cout << "Charakter: neutralny" << endl;
    if(getCharakter() ==dobry)
        cout << "Charakter: dobry" << endl;
    if(getCharakter() ==zly)
        cout << "Charakter: zly" << endl;
}
void Gracz::ZalozEkwipunek(Przedmiot* p)
{
    string odp;
    cout<<"Graulacje! Zdobyles nowy przedmiot:\n\n" << p->getNazwa_przedmiotu()<< "\nDodatek do sily: "<< p->getStat_sila() << "\nDodatek do mocy: " << p->getStat_moc() << "\nDodatek do szybkosci: " << p->getSzybkosc() << "\nDodatek do zycia: " << p->getStat_zycie() << "\nCzy chcesz go zalozyc? [tak/nie]" <<endl;
    cout<<"Twoj aktualny ekwipunek:\n"<<endl;
    PokazEkwipunek();
    cout<<"Czy chcesz zalozyc nowy przedmiot?"<<endl;
    while(1)
    {
        cin >>odp;
        if(odp=="tak")
        {
            char znak= p->getRodzaj();
            switch(znak)
            {
            case 98:
                ZdejmijEkwipunek(ekwipunek.getBron());
                ekwipunek.setBron(p);
                break;
            case 110:
                ZdejmijEkwipunek(ekwipunek.getNogi());
                ekwipunek.setNogi(p);
                break;
            case 112:
                ZdejmijEkwipunek(ekwipunek.getPancerz());
                ekwipunek.setPancerz(p);
                break;
            default:
                cout<< "Blad przy wczytywaniu rodzaju przedmiotu" <<endl;
                break;
            }
            moc=moc+p->getStat_moc();
            sila=sila+p->getStat_sila();
            szybkosc=szybkosc+p->getSzybkosc();
            zycie=zycie+p->getStat_zycie();
            cout << "Oto twoj obecny ekwipunek i statystyki:\n"<<endl;
            PokazEkwipunek();
            PokazStatystyki();
            break;
        }
        else if(odp=="nie")
        {
            cout << "Zostawiasz przedmiot"<<endl;
            break;
        }
        else
            cout << "Zle polecenie! Podaj jeszcze raz!"<<endl;
    }
}
void Gracz::ZdejmijEkwipunek(Przedmiot* p)
{
    if(p->getNazwa_przedmiotu()!="")
    {
        moc=moc-p->getStat_moc();
        sila=sila-p->getStat_sila();
        szybkosc=szybkosc-p->getSzybkosc();
        zycie=zycie-p->getStat_zycie();
    }
}
void Gracz::PokazEkwipunek()
{
    cout << "Twoja bron: " << ekwipunek.getBron()->getNazwa_przedmiotu()<<endl;
    cout << "Twoj pancerz: " << ekwipunek.getPancerz()->getNazwa_przedmiotu()<<endl;
    cout << "Twoje buty: " << ekwipunek.getNogi()->getNazwa_przedmiotu()<<endl;
}
void Gracz::SmiercGracza()
{
    cout << "Twoja postac ginie i traci zloto. Nastepnie zostaje wywieziona na taczce\n z pola walki do najblizszego uzdrowiciela."<<endl;
    setZloto(0);
    WyleczGracza();
}
void Gracz::Lvlup()
{
    setPoziom(getPoziom()+1);
    setZycie(getZycie()+100);
    WyleczGracza();
    setMax_doswiadczenie(getMax_doswiadczenie()*getPoziom());
    setMoc(getMoc()+10);
    setSila(getSila()+10);
    cout<<"Zyskujesz nowy poziom! Twoj aktualny poziom to: "<<getPoziom()<<"!"<<endl;
    cout<<"Aktualne statystyki:\n"<<endl;
    PokazStatystyki();
}
void Gracz::WyleczGracza()
{
    setAktualne_zycie(getZycie());
}
