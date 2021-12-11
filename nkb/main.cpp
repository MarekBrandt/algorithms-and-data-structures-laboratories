#include <iostream>
using namespace std;

void wypisz(int liczba)
{
    char liczbaLit;
    if (liczba < 10)
        cout << liczba;
    else
    {
        liczbaLit = liczba + 55;
        cout << liczbaLit;
    }
}

void zamien(int liczba, int podstawa)
{
    //podziel liczba przez podstawa, zapisz reszta,
    //wywolaj ponownie dla liczba / podstawa caloliczbowe
    //jesli liczba < podstawa zakoncz

    if (liczba < podstawa) wypisz(liczba);
    else if (podstawa == 1)
    {
        for (int i = 0; i < liczba; i++)
        {
            cout << podstawa;
        }
    }
    else
    {
        int reszta;

        reszta = liczba % podstawa;

        liczba /= podstawa;
        zamien(liczba, podstawa);

        wypisz(reszta);
    }
}

int bity(int liczba)
{
    int ileBitow = 1;
    while (liczba >= 2)
    {
        liczba /= 2;
        ileBitow++;
    }
    return ileBitow;
}

int main()
{
    int wierszy, ileBitow;

    cin >> wierszy;

    int liczba = wierszy - 1;

    ileBitow = bity(liczba);

    int ileCyfr;
    for (int i = 0; i < wierszy; i++)
    {
        ileCyfr = bity(i);
        for (int j = 0; j < (ileBitow - ileCyfr);j++) cout << ".";
        zamien(i, 2);
        cout <<" "<<i<< endl;
    }

}
