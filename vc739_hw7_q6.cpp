#include<iostream>
#include <cstdlib>

using namespace std;

int binarySearch(int arr[], int arrSize, int val);
int main() {

	int array[10] = { 1, 7, 13, 22, 34, 45, 47, 54, 57, 65 };

	cout << binarySearch(array, 10, 57) << endl;

	return 0;
}

int binarySearch(int arr[], int arrSize, int val) {

	int low = 0;
	int high = arrSize - 1;
	int mid;


	while (low <= high) {
		mid = (low + high) / 2;

		if (val == arr[mid]) {
			return mid;
		}
		else if (val > arr[mid]) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}

	}
	return -1;
}