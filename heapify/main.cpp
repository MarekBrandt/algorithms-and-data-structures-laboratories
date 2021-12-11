#include <iostream>
using namespace std;

void print(int tab[], int len) {
    for(int i = 0; i<len; i++){
        std::cout << tab[i]<<" ";
    }std::cout <<std::endl;
}

int parent(int i)
{
    return i/2;
}

int left(int i)
{
    return i*2;
}

int right(int i)
{
    return (i*2)+1;
}

void heapify(int arr[], int i, int len)
{
    int maxps;
    int l = left(i);
    int r = right(i);
    if (l <= len && arr[l-1] > arr[i-1])
        maxps = l;
    else
        maxps=i;
    if (r <= len && arr[r-1] > arr[maxps-1])
        maxps = r;
    if (maxps != i)
    {
        int temp = arr[i-1];
        arr[i-1] = arr[maxps-1];
        arr[maxps-1] = temp;
        heapify(arr, maxps, len);
    }
}

void budowanieKopca (int arr[], int len)
{
    for (int i = parent(len); i > 0; i--)
    {
        heapify(arr, i, len);
        print(arr, len);
    }
}

int main() {
    int size;
    while( cin >> size) {
        int * tab = new int[size];
        for(int i = 0; i < size; i++) {
            cin >> tab[i];
        }
        budowanieKopca(tab, size);
    }
    return 0;
}
