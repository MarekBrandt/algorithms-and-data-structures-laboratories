#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class LICZBA
{
public:
    unsigned long long wartosc;
    int liczbaCyfr;
};

int liczbaCyfr(unsigned long long liczba)
{
    /*return (int)(log10(liczba)+1);*/
    /*return (liczba < 10 ? 1 :
            (liczba < 100 ? 2 :
             (liczba < 1000 ? 3 :
              (liczba < 10000 ? 4 :
               (liczba < 100000 ? 5 :
                (liczba < 1000000 ? 6 :
                 (liczba < 10000000 ? 7 :
                  (liczba < 100000000 ? 8 :
                   (liczba < 1000000000 ? 9 :
                    (liczba < 10000000000 ? 10 :
                     (liczba < 100000000000 ? 11 :
                      (liczba < 1000000000000 ? 12 :
                       (liczba < 10000000000000 ? 13 :
                        (liczba < 100000000000000 ? 15 :
                         (liczba < 1000000000000000 ? 16 :
                          (liczba < 10000000000000000 ? 17 :
                           (liczba < 100000000000000000 ? 18 :
                            (liczba < 1000000000000000000 ? 19 :
                             20))))))))))))))))));*/
    string x = to_string(liczba);
    return x.length();
}

int main() {
    int wierszy, liczb;
    cin >> wierszy;
    for(int i = 0; i<wierszy; i++)
    {
        cin >> liczb;

        LICZBA * tab = new LICZBA[liczb];
        unsigned long long * tab2 = new unsigned long long[liczb];
        for(int j = 0; j<liczb; j++)
        {
            unsigned long long wczyt;
            cin >> wczyt;
            tab[j].wartosc = wczyt;
            tab[j].liczbaCyfr = liczbaCyfr(wczyt);
        }


        int indeks, max=0;
        for(int k=0; k<liczb; k++)
        {
            for(int j=0; j<liczb; j++)
            {
                if(j==0)
                {
                    indeks = 0;
                    max= tab[j].liczbaCyfr;
                    tab[j].liczbaCyfr = 0;
                }
                else if(tab[j].liczbaCyfr>=max)
                {
                    tab[indeks].liczbaCyfr = max;
                    max = tab[j].liczbaCyfr;
                    tab[j].liczbaCyfr=0;
                    indeks = j;
                }
            }
            tab2[liczb-k-1] = tab[indeks].wartosc;
        }

        for(int j = 0; j<liczb; j++)
            cout << tab2[j]<<" ";

        cout << endl;


        delete [] tab2;
        delete [] tab;
    }
    return 0;
}