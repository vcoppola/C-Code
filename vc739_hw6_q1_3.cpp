#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

void resizeSortArray(int *&arr2, int currentSize, int newSize, int newNum);
void reverse(char arr[], int arrSize);
const int SIZE = 100;
int main() {

	int arrSize = 6;
	int arr2Size = 10;
	int newSize = arr2Size + 1;
	int i, j, k;
	
	char arr[6] = { 'a', 'e', 'i', 'o', 'u', 'y' };
	int *arr2 = new int[arr2Size];
	int oneMore = 7;

	reverse(arr, arrSize);				//Question 1 function call

	for (i = 0; i < arrSize; i++) {		//Print arr: reverse array
		cout << arr[i] << ' ';
	}
	cout << endl; 
	
	for (j = 1; j <= arr2Size; j++) {	//Populate 2nd array
		arr2[j] = j * 2;
	}

	resizeSortArray(arr2, arr2Size, newSize, oneMore); //Question 2 function call

for (k = 1; k <= newSize; k++) {	//print 2nd array
		cout << arr2[k] << ' ';
	}

delete[] arr2;

	cout << endl;
								
	int max = 0;			//Question 3: Vector Histogram
	int inputVal = 0;
	
	int *p = new int[SIZE];
	vector<int> values;

	for (int i = 0; i < SIZE; i++)
	{
		p[i] = 0;
	}

	cout << "Enter grades of the student (-1 to QUIT) \n";

	while (inputVal != -1){
		cin >> inputVal;
		values.push_back(inputVal);
		
		if (inputVal > max)
			max = inputVal;

		if (inputVal >= 0)
			p[inputVal]++;			//Determines number of times grade is entered by the user
	} 
	
	for (int j = 0; j <= max; j++)  //Display output
		if (p[j] != 0)
			cout << "Number of " << j << "'s: " << p[j] << endl;
		
	delete[] p;

	return 0;
}

void reverse(char arr[], int arrSize) {

	char *ptrBegin = arr;
	char *ptrEnd = arr + arrSize - 1;

	while (ptrBegin < ptrEnd) {
		char t = *ptrBegin;
		*ptrBegin = *ptrEnd;
		*ptrEnd = t;
		ptrBegin++;
		ptrEnd--;
	}
}
void resizeSortArray(int *&arr, int currentSize, int newSize, int newNum) {

	int *temp = new int[newSize];
	int k, tmp;

	for (int i = 0; i < currentSize; i++) {
		temp[i] = arr[i];
	}
	
	arr = temp;

	temp[currentSize++] = newNum;

	for (int j = 0; j < newSize; j++) {
		k = j;

		while (k > 0 && temp[k] < temp[k - 1]) {
			tmp = temp[k];
			temp[k] = temp[k - 1]; 
			temp[k - 1] = tmp;
			k--;
		}
	}
}





