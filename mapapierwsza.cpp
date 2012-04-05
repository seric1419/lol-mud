#include "mapapierwsza.h"
int MapaPierwsza::Start()
{
    fstream plik_odczyt("poczatek.txt", ios::in);
    if( plik_odczyt.good())
    {
        string napis;
        int pos=0;
        while(!plik_odczyt.eof())
        {
            getline(plik_odczyt, napis );
            cout << napis << endl;
        }
        ///////////////////////////////////////////////////////////////////////
        cin.ignore();
        while(1)
        {
            getline(cin,napis);
            cout<<endl;
            if(napis=="pomoc")
            {
                cout<<"Aby spojrzec wokol siebie wpisz polecenie \"spojrz\"." <<endl;
                cout<<"Mozesz sprobowac wejsc w interakcje z postaciami/przedmiotami"<<endl;
                cout<<"Aby zakonczyc gre wpisz \"zakoncz\". Twoj stan gry zostanie\nzapisany jesli sobie tego zazyczysz."<<endl;
                cout<<"Jako ze to poczatek, dam Ci pewna podpowiedz: \nwpisz\"porozmawiaj ze straznikiem\""<<endl;
            }
            else if(napis=="spojrz")
            {
                cout<<"Cela swieci pustka. Przed drzwiami stoi straznik."<<endl;
            }
            else if(napis=="porozmawiaj ze straznikiem")
            {
                cout<<"-Ty plugawy szpiegu! Nie zamierzam z toba rozmawiac!"<<endl;
                pos=1;
                break;
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
            else cout << "Nie rozumiem twojego polecenia...jesli nie wiesz co zrobic, sprobuj wpisac pomoc"<<endl;
        }
        if(pos==1)
        {
            cout<<"Straznik wyraznie poirytowany twoja osoba udaje sie do pomieszczenia obok."<<endl;
            cout<<"Czas w samotnosci strasznie sie dluzy, az do momentu gdy otwieraja sie drzwi."<<endl;
            cout<<"Niska, gruba i brodata postac staje przed twoimi oczami."<<endl;
            cout<<"-Niestety, skonczylo sie jedzenie dla wiezniow.Ale niech strace, \n dam Ci lyk gorzalki. ";
            cout<<"Probujesz trunku od nieznajomego, a on w tym \nczasie przedstawia sie:"<<endl;
            cout<<"-Zwa mnie Gragas, przynajmniej tam, na wolnosci."<<endl;
            while(1)
            {
                getline(cin,napis);
                cout<<endl;
                if(napis=="pomoc")
                {
                    cout<<"Aby spojrzec wokol siebie wpisz polecenie \"spojrz\"." <<endl;
                    cout<<"Mozesz sprobowac wejsc w interakcje z postaciami/przedmiotami"<<endl;
                    cout<<"Aby zakonczyc gre wpisz \"zakoncz\". Twoj stan gry zostanie\nzapisany jesli sobie tego zazyczysz."<<endl;
                }
                else if(napis=="spojrz")
                {
                    cout<< "Przed Toba stoi Gragas. Mozesz sprobowac z nim porozmawiac."<<endl;
                }
                else if(napis=="porozmawiaj z Gragasem" || napis=="porozmawiaj z Gragas"|| napis=="porozmawiaj z gragasem" || napis=="porozmawiaj z gragas")
                {
                    cout<<"-A wiec niczego nie pamietasz...coz, moge ci powiedziec to co wiem."<<endl;
                    cout<<" Znaleziono Cie wraz z kompanami w lesie na polnoc stad.\n Byles w trakcie wykonywania zadania dla krola Dalmacji."<<endl;
                    cout<<" Przechodzenie tak blisko wroga nie bylo najlepszym pomyslem.\n Wiekszosc twoich towarzyszy polegla. Czesci jeszcze szukaja najemnicy krola."<<endl;
                    cout<<" Chcesz jeszcze o cos zapytac?"<<endl;
                    pos=2;
                    break;
                }
                else if(napis=="zakoncz")
                {
                    getGracz()->ZapiszPostac();
                    break;
                }
                else if(napis=="zapisz")
                {
                    getGracz()->ZapiszPostac();
                }
                else cout << "Nie rozumiem twojego polecenia...jesli nie wiesz co zrobic, sprobuj wpisac pomoc"<<endl;
            }
        }
        if(pos==2)
        {
            while(1)
            {
                getline(cin,napis);
                cout<<endl;
                if(napis=="tak")
                {
                    cout<<"Slucham?"<<endl;
                }
                else if(napis=="nie")
                {
                    cout<<"Bywaj zatem."<<endl;
                    pos=3;
                    break;
                }
                else if(napis=="zapytaj o krola")
                {
                    cout<<"W Dalmacji panuje Jarvan III. Cos jeszcze?"<<endl;
                    cout<<""<<endl;
                }
                else if(napis=="zapytaj o zadanie" || napis=="zapytaj o misje")
                {
                    cout<<"Nie mam pojecia co przyprowadzilo cie az tutaj, \njednakze musialo to byc cos bardzo waznego. Cos jeszcze?"<<endl;
                }
                else if(napis=="pomoc")
                {
                    cout<<"Mozesz popytac Gragasa o rozne rzeczy. Jesli nie jestes zainteresowany, wpisz \"nie\""<<endl;
                    cout<<"Aby zakonczyc gre wpisz \"zakoncz\". Twoj stan gry zostanie\nzapisany jesli sobie tego zazyczysz."<<endl;
                }
                else if(napis=="zakoncz")
                {
                    getGracz()->ZapiszPostac();
                    break;
                }
                else if(napis=="zapisz")
                {
                    getGracz()->ZapiszPostac();
                }
                else cout << "Nie rozumiem twojego polecenia...jesli nie wiesz co zrobic, sprobuj wpisac pomoc"<<endl;
            }
        }
        if(pos==3)
        {
            cout<<"Gragas wychodzi. Wszechobecna cisza sprawia, ze wyostrza ci sie sluch.\nPodsluchujesz rozmowe straznika, ktory okazuje sie prowadzi nielegalne interesy.";
            cout<<"Nastaje noc. Rano straznik budzi cie, wzywajac na przesluchanie."<<endl;
            cout<<"-Wiec mowisz ze nic nie pamietasz tak? I myslisz ze uwierze w ta bajeczke?"<<endl;

            while(1)
            {
                getline(cin,napis);
                cout<<endl;
                if(napis=="pomoc")
                {
                    cout<<"(twoja kolej, mozesz upierac sie przy swoim zdaniu mowiac \"nic nie pamietam\","<<endl;
                    cout<<"badz wcisnac mu jakies bzdury piszac \"wymysl cos\". \nMozesz takze opowiedziec o strazniku"<<endl;
                    cout<<"Aby zakonczyc gre wpisz \"zakoncz\". Twoj stan gry zostanie\nzapisany jesli sobie tego zazyczysz."<<endl;
                }
                else if(napis=="nic nie pamietam")
                {
                    cout<<"<zostajesz uderzony w twarz>\n-Lzesz jak pies! Ale skoro taka jest twoja wola, niech bedzie.\n Jutro odbedzie sie Twoja egzekucja."<<endl;
                    pos=4;
                    break;
                }
                else if(napis=="wymysl cos")
                {
                    cout<<"Yhmmm, wiec tak to wygladalo. Pojde teraz sprawdzic czy to o czym mowiles \n zgadza sie z naszymi danymi."<<endl;
                    pos=4;
                    break;
                }
                else if(napis=="opowiedz o strazniku")
                {
                    cout<<"Myslisz ze obchodzi mnie jakis straznik?! \n Skoro taka jest twoja wola, niech bedzie.\n Jutro odbedzie sie Twoja egzekucja."<<endl;
                    getGracz()->setCharakter(zly);
                    pos=4;
                    break;
                }
                else if(napis=="zakoncz")
                {
                    getGracz()->ZapiszPostac();
                    break;
                }
                else if(napis=="zapisz")
                {
                    getGracz()->ZapiszPostac();
                }
                else cout << "Nie rozumiem twojego polecenia...jesli nie wiesz co zrobic, sprobuj wpisac pomoc"<<endl;
            }
        }
        if(pos==4)
        {
            if(napis=="nic nie pamietam" || napis=="opowiedz o strazniku")
            {
                cout<<"\nNastaje dzien egzekucji. Straznik prowadzi cie na spotkanie z katem,\n az tu nagle zza rogu wyskakuje wielki polarny niedzwiedz ubrany w zbroje."<<endl;
                cout<<"-"<<getGracz()->getNazwa()<<"! Wybacz tak dluga zwloke. Kim jestem? Ty na prawde nic nie pamietasz...\n Nazywam sie Volibear i jestem twoim sojusznikiem. \n Nie czas na wyjasnienia, musimy sie stad zabierac."<<endl;
                cout<<"Idziecie do tajnego przejscia, gwarantujacego szybka ucieczke, \nale po drodze napotykacie dziwnie ubrana luczniczke"<<endl;
                cout<<"-Ashe! Gdzie jest Nunu??"<<endl;
                cout<<"-Wzieli go zywcem, mowili cos o wyslaniu go do zoo... O! "<<getGracz()->getNazwa()<<"! \n Dobrze cie widziec. To co robimy?"<<endl;
                while(1)
                {
                    getline(cin,napis);
                    cout<<endl;
                    if(napis=="ratuj Nunu" || napis=="uratuj Nunu")
                    {
                        cout<<"Idziecie poszukac Nunu. Odnajdujecie go w wielkiej pustej sali."<<endl;
                        cout<<"-Myslelismy ze cie schwytano!"<<endl;
                        cout<<"-Moj goryl ich zjadl. Zabierajmy sie stad."<<endl;
                        getGracz()->setCharakter(dobry);
                        pos=5;
                        break;
                    }
                    else if(napis=="uciekaj")
                    {
                        cout<<"-Miejmy nadzieje ze sobie poradzi... Zabierajmy sie stad!"<<endl;
                        getGracz()->setCharakter(zly);
                        pos=5;
                        break;
                    }
                    else if(napis=="pomoc")
                    {
                        cout<<"Wybierz co zrobicie z Nunu"<<endl;
                        cout<<"Aby zakonczyc gre wpisz \"zakoncz\". Twoj stan gry zostanie\nzapisany jesli sobie tego zazyczysz."<<endl;
                    }
                    else if(napis=="zakoncz")
                    {
                        getGracz()->ZapiszPostac();
                        break;
                    }
                    else if(napis=="zapisz")
                    {
                        getGracz()->ZapiszPostac();
                    }
                    else cout << "Nie rozumiem twojego polecenia...jesli nie wiesz co zrobic, sprobuj wpisac pomoc"<<endl;
                }
            }
            else if(napis=="wymysl cos")
            {
                cout<<"\nCzekanie na wyrok zostaje zaklocone. Mala postac ubrana na zimowo \nwchodzi do pomieszczenia."<<endl;
                cout<<"-Ooo... wiec to tutaj jestes!"<<endl;
                cout<<"Nastepnie przez drzwi wchodzi wielki zimowy goryl. Maly chlopiec wydaje\nmu polecenie po czym kraty od twojej celi zostaja calkowicie powyginane."<<endl;
                cout<<"-Nic nie pamietasz? Jestem Nunu a to moj podopieczny. \n Ruszajmy, pozostali na nas czekaja.\n";
                cout<<"Po drodze spotykacie straznika.\nWyglada on na przestraszonego i niezdolnego do walki."<<endl;
                while(1)
                {
                    getline(cin,napis);
                    cout<<endl;
                    if(napis=="zabij straznika")
                    {
                        cout<<"Likwidujecie przeszkode i spotykacie pozostalych kompanow,\npo czym uciekacie tajnym przejsciem"<<endl;
                        getGracz()->setCharakter(zly);
                        pos=5;
                        break;
                    }
                    else if(napis=="zostaw straznika")
                    {
                        cout<<"Omijacie straznika i spotykacie pozostalych kompanow,\npo czym uciekacie tajnym przejsciem"<<endl;
                        getGracz()->setCharakter(dobry);
                        pos=5;
                        break;
                    }
                    else if(napis=="pomoc")
                    {
                        cout<<"Zdecyduj co zrobic ze straznikiem"<<endl;
                        cout<<"Aby zakonczyc gre wpisz \"zakoncz\". Twoj stan gry zostanie\nzapisany jesli sobie tego zazyczysz."<<endl;
                    }
                    else if(napis=="zakoncz")
                    {
                        getGracz()->ZapiszPostac();
                        break;
                    }
                    else if(napis=="zapisz")
                    {
                        getGracz()->ZapiszPostac();
                    }
                    else cout << "Nie rozumiem twojego polecenia...jesli nie wiesz co zrobic, sprobuj wpisac pomoc"<<endl;

                }

            }
        }
        if(pos==5)
        {
            cout<<"Uciekacie z wrogiej fortecy. Kompani opowiadaja ci twoja historie.\nOkazujesz sie byc jednym z elitarnej brygady krola Jarvana III."<<endl;
            cout<<"Anivia, ptak mrozu sluzacy Ashe wyszukal dla was najbezpieczniejsza trase."<<endl;
            cout<<"Zmierzacie do stolicy Dalmacii."<<endl;
            getchar();
            cout << "\n\n\n\n\n\n\n\n///////////////////////////////////////////////////////////////////////////////\n";
            cout << "///////////////////////////////////////////////////////////////////////////////\n";
            cout << "/////////////////////////////KONIEC EPIZODU PIERWSZEGO!////////////////////////\n";
            cout << "///////////////////////////////////////////////////////////////////////////////\n";
            cout << "///////////////////////////////////////////////////////////////////////////////\n";
            getGracz()->setPostep(1);
            plik_odczyt.close();
            return 2;
        }
    }else cout <<"Nie znaleziono pliku z poczatkiem przygody!"<<endl;
    return 0;
}

MapaPierwsza::MapaPierwsza(Gracz* g)
{
    setGracz(g);
}
MapaPierwsza::MapaPierwsza()
{
}
