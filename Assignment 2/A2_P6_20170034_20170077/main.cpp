#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;
const int maxn = 1e5 , maxs = 1e4;

int upperBound(int* arr , int n , int x);
void binaryInsertion(int* arr, int n);

void insertion(int* arr, int n);

int measure (void(*srt)(int*,  int) , int* arr ,int h);
void gen (int* a1 , int* a2 , int s);

int main()
{
    srand (time(NULL));

    ofstream ins , bins , sz;
    ins.open("ins.txt" , ios::out);
    bins.open("binaryins.txt" , ios::out);
    sz.open("size.txt" , ios::out);

    int* arr1;
    int* arr2;

    for (int i = 1 ; i<= maxs ; i*=2) // change here
    {
        arr1 = new int [i];
        arr2 = new int [i];

        gen(arr1,arr2,i);

        sz << i << "\n";
        ins<<measure(insertion,arr1,i) << "\n";
        bins<<measure(binaryInsertion,arr2,i) << "\n";

        delete arr1;
        delete arr2;
    }

    ins.close();
    bins.close();
    sz.close();
    return 0;
}


int upperBound(int* arr, int n, int x) {
    int l = 0;
    int h = n;
    while (l < h) {
        int mid = (l + h) / 2;
        if (x >= arr[mid]) {
            l = mid + 1;
        } else {
            h = mid;
        }
    }
    return l;
}
void binaryInsertion(int* arr , int n)
{
    int i , key , idx ;
    for (i = 1; i < n; i++) {
        key = arr[i];
        idx = upperBound(arr,i,key);
        arr[idx] = key;
        for (int j = i ; j>idx ; ++j)
        {
            arr[j] = arr[j-1];
        }
        arr[idx] = key;
    }
}


void insertion(int* arr , int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


int measure (void(*srt)(int*, int) , int* arr , int h)
{
    int st = clock();
    srt(arr,h);
    return (clock() - st);
}
void gen (int* a1 , int* a2 , int s)
{
    for (int i = 0 ; i<s ; ++i)
    {
        a1[i] = a2[i] = rand()%maxn;
    }
}


