#include <iostream>
using namespace std;

void print(int tab[], int len) {
    for(int i = 0; i<len; i++){
        std::cout << tab[i]<<" ";
    }std::cout <<std::endl;
}

void shellSort(int * tab, int size) {
    for (int gap = size/2; gap >= 1; gap /=2) {
        for (int i = gap; i < size; i++) {
            int temp = tab[i];
            int j;
            for(j = i; j >= gap && tab[j-gap] > temp; j -=gap) {
                tab[j] = tab[j - gap];
            }
            tab[j] = temp;
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
        shellSort(tab, size);
        delete [] tab;
    }
    return 0;
}
