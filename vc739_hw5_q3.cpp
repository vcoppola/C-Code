#include<iostream>
using namespace std;



void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);
void splitParity(int arr[], int arrSize);
void printArray(int arr[], int arrSize);
int main(){

	int arr1[10] = { 9, 2, 14, 12, -3 };
	int arr1Size = 5;

	int arr2[10] = { 21, 12, 6, 7, 14 };
	int arr2Size = 5;

	int arr3[10] = { 3, 6, 4, 1, 12 };
	int arr3Size = 5;

	reverseArray(arr1, arr1Size);
	printArray(arr1, arr1Size);
	
	removeOdd(arr2, arr2Size);
	printArray(arr2, arr2Size);

	splitParity(arr3, arr3Size);
	printArray(arr3, arr3Size);

	return 0;
}

void reverseArray(int arr[], int arrSize) {

	int temp = 0;
	
	for (int i = 0; i < arrSize/2; ++i){
		temp = arr[i];
		arr[i] = arr[arrSize - i - 1];
		arr[arrSize-i-1] = temp; 
	}

}

void removeOdd(int arr[], int& arrSize) {

	for (int i = 0; i < arrSize; i++) {
		if (arr[i] % 2 == 0) {
			arr[i + 1] = arr[i];
			arr[i + 1] = arr[i + 2];
			arr[i + 2] = arr[i + 3];
			arr[i + 3] = arr[i + 4];
		}
	}
}

void splitParity(int arr[], int arrSize) {
	
	int i, j, temp, k;
	
	for (i = 1; i < arrSize; i++){
		for (j = 0; j<i ; j++){
			if ((arr[i] % 2) != 0 && (arr[j] % 2) == 0)
			{
				temp = arr[j];
				arr[j] = arr[i];
				for (k = i; k>j; k--)
					arr[k] = arr[k - 1];

				arr[k + 1] = temp;
			}
		}
	}
	
	
}

void printArray(int arr[], int arrSize) {
	
	int i;

	for (i = 0; i < arrSize; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

