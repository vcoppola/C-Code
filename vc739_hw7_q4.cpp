#include<iostream>

using namespace std;

int jumpIt(int integer[], int index, int boardSize);
int min(int a, int b);
int main() {

	int size = 6;
	int array[] = { 0, 3, 80, 6, 57, 10 };

	cout << jumpIt(array, 0, 6) << endl;

	return 0;
}
int jumpIt(int array[], int index, int size)
{
		if (index >= size) 
			return 0;
		else 
			return min(array[index] + jumpIt(array, index + 1, size),
			array[index] + jumpIt(array, index + 2, size)
		);
}

int min(int a, int b) {
		if (a < b) return a;
		else return b;
}
