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

int main()
{
    int ile;
    int X, P;

    scanf("%d", &ile);

    for (int i = 0; i < ile; i++)
    {
        scanf("%d %d", &X, &P);
        zamien(X, P);
        printf("\n");

    }
}

