#include <iostream>
#include <cmath>
using namespace std;

void print(int tab[], int len) {
    for(int i = 0; i<len; i++){
        std::cout << tab[i]<<" ";
    }std::cout <<std::endl;
}

void shellSort(int * tab, int size) {
    int k = pow(2, floor(log2(size))) -1;
    while (k >= 1) {
        for (int i = k; i < size; i++) {
            int x = tab[i];
            int j = i;
            while (j>=k && x < tab[j-k]) {
                tab[j] = tab[j-k];
                j-=k;
            }
            tab[j] = x;
        }
        k = (k+1)/2 -1;
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
