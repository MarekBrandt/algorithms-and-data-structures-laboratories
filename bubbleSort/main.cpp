#include <iostream>

void zamien(int tab[], int fIndex, int sIndex)
{
    int temp = tab[fIndex];
    tab[fIndex] = tab[sIndex];
    tab[sIndex] = temp;
}

void sort(int tab[], int lIndex, int size) {
    for (int j = size -1; j >= 0; j--) {
        for ( int i = lIndex; i < j; i++) {
            if(tab[i] > tab[i+1]) {
                zamien(tab, i, i+1);
            }
        }
    }
}

int main() {
    int tab[] = {1,7,2,8,11,4,17,22,12};
    int size = sizeof tab / sizeof(int);
    sort(tab, 0, size);
    for(int i = 0; i<size; i++){
        std::cout << tab[i]<<" ";
    }std::cout <<std::endl;
    return 0;
}
