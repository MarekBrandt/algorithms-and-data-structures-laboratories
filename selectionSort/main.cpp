#include <iostream>
using namespace std;

void print(int tab[], int len) {
    for(int i = 0; i<len; i++){
        printf("%d ", tab[i]);
    }printf("\n");
}

void zamien(int tab[], int fIndex, int sIndex)
{
    int temp = tab[fIndex];
    tab[fIndex] = tab[sIndex];
    tab[sIndex] = temp;
}

int maxElem(int tab[], int n) {
    int max = 0;
    for (int i = 1; i < n; i++) {
        if(tab[i] > tab[max]) {
            max = i;
        }
    }
    return max;
}


void selectionSort(int tab[], int size) {
    int maxIndex;
    for(int j = size; j >= 2; j--) {
        maxIndex = maxElem(tab, j);
        if(maxIndex != j-1) {
            zamien(tab,j-1,maxIndex);
        }
        print(tab, size);
    }
}

int main() {
    int size;
    while( cin >> size) {
        int * tab = new int[size];
        for(int i = 0; i < size; i++) {
            cin >> tab[i];
        }
        selectionSort(tab, size);
    }

    return 0;
}
