#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <chrono>
#include <random>

using namespace std;
const int maxn = 1e5, maxs = 7e4;

int upperBound(int* arr, int n, int x);
void binaryInsertion(int* arr, int n);

void insertion(int* arr, int n);

int measure(void(*srt)(int*, int), int* arr, int h);
void gen(int* a1, int* a2, int s);
mt19937 rng;
int main()
{
	rng.seed(chrono::steady_clock::now().time_since_epoch().count());

	ofstream graph;
	graph.open("graph.csv");

	int* arr1;
	int* arr2;


	int cursz = 10;
	graph << "Data Size,Insertion Sort,Binary Insertion Sort\n";
	for (int i = cursz; i <= maxs; i += cursz) // change here
	{
		arr1 = new int[i];
		arr2 = new int[i];

		gen(arr1, arr2, i);

		graph << i << "," << measure(insertion, arr1, i) << "," << measure(binaryInsertion, arr2, i) << "\n";

		if (i >= cursz * 10) cursz *= 10;
		delete arr1;
		delete arr2;
	}

	graph.close();
	return 0;
}


int upperBound(int* arr, int n, int x) {
	int l = 0;
	int h = n;
	while (l < h) {
		int mid = (l + h) / 2;
		if (x >= arr[mid]) {
			l = mid + 1;
		}
		else {
			h = mid;
		}
	}
	return l;
}
void binaryInsertion(int* arr, int n)
{
	int i, key, idx;
	for (i = 0; i < n; i++) {
		key = arr[i];
		idx = upperBound(arr, i, key);
		for (int j = i; j > idx; --j)
		{
			arr[j] = arr[j - 1];
		}
		arr[idx] = key;
	}
}


void insertion(int* arr, int n)
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

int measure(void(*srt)(int*, int), int* arr, int h)
{
	auto startTime = std::chrono::high_resolution_clock::now();
	srt(arr, h);
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