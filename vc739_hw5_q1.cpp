#include<iostream>
using namespace std;

const int SIZE = 20;
int minInArray(int arr[], int arrSize);
int main() {

	int i = 0;
	int arr[SIZE];
	int min, num;

	cout << "Please enter 20 integers separated by a space: " << endl;

	for (i; i < SIZE; i++) {
		cin >> num;
		arr[i] = num;
		}
	
	min = minInArray(arr, SIZE);

	cout << "The minimum value is " << min << ", and it is located in the following indices: ";

		for (i = 0; i < SIZE; i++) {
			if (arr[i] == min) {
				cout << i << " ";
			}
		}
			
	cout << endl;

	return 0;
}


int minInArray(int arr[], int arrSize) {

	int i = 0;
	int lowest = arr[0];

	for (i; i < arrSize; i++) 
		if (arr[i] <= lowest) {
			lowest = arr[i];
		}

	return lowest;
}