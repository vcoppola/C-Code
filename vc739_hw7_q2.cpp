#include<iostream>
using namespace std;

bool isSorted(int arr[], int arrSize);
int sumOfSquares(int arr[], int arrSize);
int main() {

	int sum = 0;
	int size = 4;
	int size2 = 5;
	int arr[] = { 2, -1, 3, 10 };
	int arr2[] = { 2, 3, 75, 10, 20 };


	cout << sumOfSquares(arr, size) << endl;
	
	if (isSorted(arr2, size2) == true)
		cout << "The array is sorted" << endl;
	else
		cout << "The array is not sorted" << endl;
		
	return 0;
}

int sumOfSquares(int arr[], int arrSize) {
	if (arrSize <= 0){
		return 0;
	}	
	else {
			return (pow(arr[arrSize - 1], 2)) + sumOfSquares(arr, arrSize -1);
	}
}

bool isSorted(int arr[], int arrSize) {
	
	if (arrSize == 0)
		return true;
	
	else if (arr[arrSize - 1] >= arr[arrSize - 2]) {
		return isSorted(arr, arrSize - 1);
	}
	else
		return false;
}
	
