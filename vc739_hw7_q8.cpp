#include<iostream>

using namespace std;

void insertionSort(int a[], int aSize);
int main() {
	int size = 6;
	int unsorted[] = { 23, 14, 56, 75, 1, 25 };

	insertionSort(unsorted, size);

	return 0;
}

void insertionSort(int a[], int aSize) {
	int key;
	int sorted[6];

	for (int i = 0; i < aSize; i++) {
		sorted[i] = a[i];

		while (i > 0 && sorted[i] < sorted[i - 1]) {
			key = sorted[i];
			sorted[i] = sorted[i - 1];
			sorted[i - 1] = key;
			key--;
		}
	}

	for (int i = 0; i < aSize; i++) {
		cout << sorted[i] << " ";
	}
	cout << endl;
}