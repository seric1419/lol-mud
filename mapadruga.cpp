#include "mapadruga.h"
void MapaDruga::Arena()
{
    cout<<"Witaj na Arenie!"<<endl;
    do
    {
        cout<<"Za chwile zmierzysz sie z potworem wylosowanym przez Arene."<<endl;
        Walka();

        string odp;
        cout << "\nKontynuowac walki na arenie? [tak/nie]" <<endl;
        while(1)
        {
            cin >>odp;
            if(odp=="tak")
            {
                cout << "\nWczytywanie nowego przeciwnika..." <<endl;
                break;
            }
            else if(odp=="nie")
            {
                cout<< "\nOpuszczasz arene..." <<endl;
                break;
            }
            else
                cout << "Nieprawidlowe polecenie! Wpisz \"tak\" lub \"nie\"" <<endl;
        }
        if(odp=="nie")
            break;
    }while(1);
}
void MapaDruga::Karczma()
{
    cout<<"Witaj przybyszu! Zechcesz wypoczac?(20 zlota)"<<endl;
    string odp;
    cin>>odp;
    while(1)
    {
        if(odp=="tak")
        {
            if(getGracz()->getZloto()>=20)
            {
                getGracz()->setZloto(getGracz()->getZloto()-20);
                getGracz()->WyleczGracza();
            }
            else cout<<"Za malo zlota!"<<endl;
            break;
        }
        else if(odp=="nie")
        {
            cout<<"Bywaj zatem!"<<endl;
            break;
        }
        else if(odp=="pomoc")
        {
            cout<<"Wpisz \"tak\" lub \"nie\""<<endl;
        }
        else cout<< "Zle polecenie, sprobuj \"pomoc\""<<endl;
    }
}
void MapaDruga::Kupowanie()
{
    cout<< "Co chcesz kupic?" << endl;
    Przedmiot* p1 = Losujprzedmiot(1);
    int wartosc1= p1->getStat_moc()*10+p1->getStat_sila()*10+p1->getStat_zycie()+p1->getSzybkosc()*10;
    cout<<" Nazwa przedmiotu   Wartosc \tSila\tMoc\tSzybkosc\tZycie"<<endl;
    cout<<"1."<<p1->getNazwa_przedmiotu()<<" za "<<wartosc1<< " zlota."<<"\t"<<p1->getStat_sila()<<"\t"<< p1->getStat_moc()<<"\t"<< p1->getSzybkosc()<< "\t\t"<< p1->getStat_zycie()<<endl;
    Przedmiot* p2 = Losujprzedmiot(2);
    int wartosc2= p2->getStat_moc()*10+p2->getStat_sila()*10+p2->getStat_zycie()+p2->getSzybkosc()*10;
    cout<<"2."<<p2->getNazwa_przedmiotu()<<" za "<<wartosc2<< " zlota." <<"\t"<<p2->getStat_sila()<<"\t"<< p2->getStat_moc()<<"\t"<< p2->getSzybkosc()<< "\t\t"<< p2->getStat_zycie()<<endl;
    Przedmiot* p3 = Losujprzedmiot(3);
    int wartosc3= p3->getStat_moc()*10+p3->getStat_sila()*10+p3->getStat_zycie()+p3->getSzybkosc()*10;
    cout<<"3."<<p3->getNazwa_przedmiotu()<<" za "<<wartosc3<< " zlota." <<"\t"<<p3->getStat_sila()<<"\t"<< p3->getStat_moc()<<"\t"<< p3->getSzybkosc()<< "\t\t"<< p3->getStat_zycie()<<endl;
    cout<<"4.Wyjscie." <<endl;
    int odp=0;
    while(odp!=4)
    {
        cin >>odp;
        switch(odp)
        {
        case 1:
            if(getGracz()->getZloto() >=wartosc1)
            {
                getGracz()->setZloto(getGracz()->getZloto()-wartosc1);
                cout << "Kupujesz " << p1->getNazwa_przedmiotu()<<" za "<<wartosc1<< " zlota." <<endl;
                getGracz()->ZalozEkwipunek(p1);
            } else cout << "Nie masz dosc zlota, aby kupic ten przedmiot!" <<endl;
            break;
        case 2:
            if(getGracz()->getZloto() >=wartosc2)
            {
                getGracz()->setZloto(getGracz()->getZloto()-wartosc2);
                cout << "Kupujesz " << p2->getNazwa_przedmiotu()<<" za "<<wartosc2<< " zlota." <<endl;
                getGracz()->ZalozEkwipunek(p2);
            } else cout << "Nie masz dosc zlota, aby kupic ten przedmiot!" <<endl;
            break;
        case 3:
            if(getGracz()->getZloto() >=wartosc3)
            {
                getGracz()->setZloto(getGracz()->getZloto()-wartosc3);
                cout << "Kupujesz " << p3->getNazwa_przedmiotu()<<" za "<<wartosc3<< " zlota." <<endl;
                getGracz()->ZalozEkwipunek(p3);
            } else cout << "Nie masz dosc zlota, aby kupic ten przedmiot!" <<endl;
            break;
        case 4:
            break;
        default:
            cout<< "Wybierz ktoras z opcji wpisujac cyfre znajdujaca sie przy niej"<<endl;
            break;
        }
    }
}
void MapaDruga::Krol()
{
    cout<<"-Witaj! Twoi towarzysze? Aaa tak, zostali wyslani na bitwe."<<endl;
    cout<<" Masz wiadomosc dla krola? Niestety poprzedni krol nie zyje\n ale jesli to cos waznego to mozesz przekazac mi."<<endl;
    cout<<"<dajesz krolowi zapieczentowana wiadomosc>\n"<<endl;
    cout<<"\"Zapraszamy do naszego Noxusowego cyrku. Mamy najbogatsza kolekcje dziwadel\nm.in fioletowy byk, pol kobieta-pol waz, szczur ninja,\ngadajace drzewo, zabojczo silny krokodyl oraz slodki pies w mundurze!\nZapraszamy serdecznie!\nZ powazaniem, Wladze Noxus.\""<<endl;
    cout<<"-Grrrr! Czy to jakies kpiny? Ja zaraz pokaze temu Nexusowi,\n ktore krolestwo ma najlepszy cyrk. \nWysylam cie na bitwe."<<endl;
}
void MapaDruga::Sklep()
{
    cout << "Witaj w sklepie! Chcesz cos kupic?" <<endl;
    string odp;
    cin >> odp;
    if(odp=="tak")
    {
        Kupowanie();
    }
    else if(odp=="nie")
    {
        cout << "Szkoda." <<endl;
        cout << "<wychodzisz ze sklepu>" <<endl;
    }
    else cout << "Nie wiem o co Ci chodzi... To chcesz cos kupic czy nie?" << endl;
}
int MapaDruga::Start()
{
    fstream plik_odczyt("miasto.txt", ios::in);
    if( plik_odczyt.good())
    {
        bool zakonczony=0;
        string napis;
        while(!plik_odczyt.eof())
        {
            getline(plik_odczyt, napis );
            cout << napis << endl;
        }
        while(1)
        {
            cout<<"\nZnajdujesz sie w miescie. Co chcesz zrobic?"<<endl;
            cout<<"1.Idz do krola."<<endl;
            cout<<"2.Arena."<<endl;
            cout<<"3.Sklep z ekwipunkiem"<<endl;
            cout<<"4.Karczma(ulecz rany za oplata)"<<endl;
            getline(cin, napis );
            if(napis=="1")
            {
                if(getGracz()->getPoziom()>=5)
                {
                    Krol();
                    zakonczony=1;
                    break;
                }
                else cout<<"Masz za niski poziom! Minimalny poziom do spotkania z krolem to 5."<<endl;
            }
            else if(napis=="2")
            {
                Arena();
                cin.ignore();
            }
            else if(napis=="3")
            {
                cout<<endl;
                Sklep();
                cin.ignore();
            }
            else if(napis=="4")
            {
                cout<<endl;
                Karczma();
                cin.ignore();
            }
            else if(napis=="pomoc")
            {
                cout<<"Wpisz ktoras z cyfr aby wybrac opcje."<<endl;
                cout<<"Aby zakonczyc gre wpisz \"zakoncz\". Twoj stan gry zostanie\nzapisany jesli sobie tego zazyczysz."<<endl;
            }
            else if(napis=="statystyki")
            {
                cout<<endl;
                getGracz()->PokazStatystyki();
            }
            else if(napis=="zakoncz")
            {
                getGracz()->ZapiszPostac();
                break;
            }
            else if(napis=="zapisz")
            {
                getGracz()->ZapiszPostac();
                cin.ignore();
            }
            else cout<<"Zle polecenie, sprobuj \"pomoc\""<<endl;
        }
        if(zakonczony==1)
        {
            getGracz()->setPostep(2);
            cout << "\n\n\n\n\n\n\n\n///////////////////////////////////////////////////////////////////////////////\n";
            cout << "///////////////////////////////////////////////////////////////////////////////\n";
            cout << "///////////////////////////KONIEC EPIZODU DRUGIEGO!////////////////////////////\n";
            cout << "///////////////////////////////////////////////////////////////////////////////\n";
            cout << "///////////////////////////////////////////////////////////////////////////////\n";
            getGracz()->ZapiszPostac();
            plik_odczyt.close();
            return 3;
        }
    }else cout <<"Nie znaleziono pliku miasto1!"<<endl;
    return 0;
}
void MapaDruga::Walka()
{
     Potwor* p = Losujpotwora();
     cout << "\n" << p->getNazwa_potwora() << " atakuje!" <<endl;
     while(p->getAktualne_zycie() !=0 && getGracz()->getAktualne_zycie() !=0)
     {
                                  string polecenie;
                                  cout << "Co teraz?\n1. Wpisz \"walcz\" aby zaczac walke silowa.\n2. Wpisz \"magia\" aby zaczac walke magiczna.\n3. Wpisz \"uciekaj\" aby sprobowac uciec.\nWybor:" << endl;
                                  cin >> polecenie;
                                  cout << endl;
                                  if(polecenie=="walcz")
                                  {
                                                                int odejmij=(getGracz()->getSila()/2)+(rand()%getGracz()->getSila());
                                                                cout << "Zadajesz " << odejmij << " obrazen!"<<endl;
                                                                for(int i=0;i<odejmij && p->getAktualne_zycie()!=0;i++)
                                                                p->setAktualne_zycie(p->getAktualne_zycie()-1);
                                                                if(p->getAktualne_zycie()!=0)
                                                                {
                                                                odejmij=(p->getStat_sila()/2)+(rand()%p->getStat_sila());
                                                                cout << "Potwor zadaje " << odejmij << " obrazen!"<<endl;
                                                                for(int i=0;i<odejmij && getGracz()->getAktualne_zycie()!=0;i++)
                                                                getGracz()->setAktualne_zycie(getGracz()->getAktualne_zycie()-1);
                                                                PokazWalczacych(p);
                                                                }


                                  }
                                  else if(polecenie=="magia")
                                  {
                                                                int odejmij=(getGracz()->getMoc()/2)+(rand()%getGracz()->getMoc());
                                                                cout << "Zadajesz " << odejmij << " obrazen!"<<endl;
                                                                for(int i=0;i<odejmij && p->getAktualne_zycie()!=0;i++)
                                                                p->setAktualne_zycie(p->getAktualne_zycie()-1);
                                                                if(p->getAktualne_zycie()!=0)
                                                                {
                                                                odejmij=(p->getStat_moc()/2)+(rand()%p->getStat_moc());
                                                                cout << "Potwor zadaje " << odejmij << " obrazen!"<<endl;
                                                                for(int i=0;i<odejmij && getGracz()->getAktualne_zycie()!=0;i++)
                                                                getGracz()->setAktualne_zycie(getGracz()->getAktualne_zycie()-1);
                                                                PokazWalczacych(p);
                                                                }
                                  }
                                  else if(polecenie=="uciekaj")
                                  {
                                                               int ucieczka=rand()%100;
                                                               if(ucieczka<getGracz()->getSzybkosc())
                                                               {
                                                                   cout << "Ucieczka udana!" << endl;
                                                                   break;
                                                               }else
                                                               {
                                                               cout << "Ucieczka nieudana!" <<endl;
                                                               int odejmij=(p->getStat_sila()/2)+(rand()%p->getStat_sila());
                                                               cout << "Potwor zadaje " << odejmij << " obrazen!"<<endl;
                                                               for(int i=0;i<odejmij && getGracz()->getAktualne_zycie()!=0;i++)
                                                               getGracz()->setAktualne_zycie(getGracz()->getAktualne_zycie()-1);
                                                               PokazWalczacych(p);
                                                               }
                                  }
                                  else
                                  cout<< "Zle polecenie. Sproboj ponownie:" <<endl;


     }
     if(getGracz()->getAktualne_zycie()==0)
     {
                    getGracz()->SmiercGracza();
     }
     else if(p->getAktualne_zycie()==0)
     {
                                cout<< "\nOdnosisz zwyciestwo!" <<endl;
                                cout<< "Otrzymujesz "<<p->getIlosc_zlota() << " zlota i " <<p->getIlosc_doswiadczenia() << " doswiadczenia!"<<endl;
                                getGracz()->setZloto(getGracz()->getZloto()+p->getIlosc_zlota());
                                getGracz()->setDoswiadczenie(getGracz()->getDoswiadczenie()+p->getIlosc_doswiadczenia());
                                if(getGracz()->getDoswiadczenie()>=getGracz()->getMax_doswiadczenie())
                                {
                                getGracz()->Lvlup();
                                SilaPotworow(getGracz()->getPoziom());
                                }
                                int los=rand()%100;
                                if(los<p->getSzansa_item())
                                getGracz()->ZalozEkwipunek(Losujprzedmiot());
     }
}
MapaDruga::MapaDruga()
{
}
MapaDruga::MapaDruga(Gracz* g)
{
    setGracz(g);
}
