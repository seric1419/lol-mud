#include "mapatrzecia.h"
int MapaTrzecia::Start()
{
    fstream plik_odczyt("bitwa.txt", ios::in);
    if( plik_odczyt.good())
    {
        string napis;
        while(!plik_odczyt.eof())
        {
            getline(plik_odczyt, napis );
            cout << napis << endl;
        }
        while(1)
        {
            getline(cin, napis );
            if(napis=="uciekaj")
            {
                if(getGracz()->getCharakter()==zly)
                    cout<<"Uciekajac zostajesz zabity wlocznia w plecy przez jakiegos chinczyka."<<endl;
                if(getGracz()->getCharakter()==dobry)
                    cout<<"Kradniesz peleryne niewidke szczurowi z kusza. Bezpiecznie uciekasz.\nW przyszlosci zostajesz dozorca nexusowego zoo."<<endl;
                break;
            }
            else if(napis=="walcz")
            {
                if(getGracz()->getCharakter()==zly)
                    cout<<"Pokonujesz wszystkich wrogow, a nastepnie zabijasz swojego krola\n i oglaszasz sie wladca nowego swiata. Twoja zona zostaje Ahri.\n Rodzi ci synka ktorego nazywasz Naruto."<<endl;
                if(getGracz()->getCharakter()==dobry)
                    cout<<"Bierzesz na siebie miliardy ulti az w koncu giniesz od trucizny Signed'a. \nDalmacja wygrywa wojne, a twoj towarzysze upamietniaja twoj wyczyn stawiajac pomnik."<<endl;
                break;
            }
            else cout<< "Zle polecenie"<<endl;
        }
        plik_odczyt.close();
    }else cout <<"Nie znaleziono pliku z bitwa!"<<endl;
    return 0;
}
MapaTrzecia::MapaTrzecia()
{
}
MapaTrzecia::MapaTrzecia(Gracz* g)
{
    setGracz(g);
}
