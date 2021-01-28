#include<iostream>

using namespace std;

int findChange(int arr01[], int arr01Size);
int main() {

	int size = 9;	
	int arr01[] = { 0, 0, 0, 0, 0, 0, 1, 1, 1 };

	cout << findChange(arr01, 9) << endl;

	return 0;
}

int findChange(int arr01[], int arr01Size) {

	int low = 0;
	int high = arr01Size - 1;
	int mid;

	while (low <= high) {
		mid = (low + high) / 2;

		if (1 == arr01[mid]) {
			return mid;
		}
		else if (1 > arr01[mid]) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
}