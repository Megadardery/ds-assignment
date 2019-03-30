#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;
const int maxn = 1e5, maxs = 5e6;

void swap(int& a, int& b);

int part(int* arr, int l, int h);
void quicksort(int* arr, int l, int h);

void merge(int* arr, int l, int m, int r);
void mergesort(int* arr, int l, int h);

int measure(void(*srt)(int*, int, int), int* arr, int l, int h);
void gen(int* a1, int* a2, int s);

#include<random>
#include<chrono>

mt19937 rng;
int main()
{
	rng.seed(chrono::steady_clock::now().time_since_epoch().count());

	ofstream quick, mrg, sz;
	ofstream graph;
	graph.open("graph.csv");
	int* arr1;
	int* arr2;

	int cursz = 10;
	graph << "Data Size,Quick Sort,Merge Sort\n";
	for (int i = cursz; i <= maxs; i += cursz) // change here
	{
		arr1 = new int[i];
		arr2 = new int[i];

		gen(arr1, arr2, i);

		graph << i << "," << measure(quicksort, arr1, 0, i - 1) << "," << measure(mergesort, arr2, 0, i - 1) << "\n";

		if (i >= cursz * 10) cursz *= 10;

		delete[] arr1;
		delete[] arr2;
	}

	graph.close();
	return 0;
}


void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


int part(int* arr, int l, int h)
{
	int pivot = arr[h];
	int i = (l - 1);

	for (int j = l; j < h; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[h]);
	return (i + 1);
}
void quicksort(int* arr, int l, int h)
{
	if (l < h)
	{
		int pi = part(arr, l, h);

		quicksort(arr, l, pi - 1);
		quicksort(arr, pi + 1, h);
	}
}


void merge(int* arr, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int* L = new int[n1];
	int* R = new int[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
	delete L;
	delete R;
}
void mergesort(int* arr, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		mergesort(arr, l, m);
		mergesort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

int measure(void(*srt)(int*, int, int), int* arr, int l, int h)
{
	auto startTime = std::chrono::high_resolution_clock::now();
	srt(arr, l, h);
	auto endTime = std::chrono::high_resolution_clock::now();
	return std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
}
void gen(int* a1, int* a2, int s)
{
	uniform_int_distribution<int> r(-maxn, maxn);
	for (int i = 0; i < s; ++i)
	{
		a1[i] = a2[i] = r(rng);
	}
}


