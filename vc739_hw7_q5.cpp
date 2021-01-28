#include<iostream>
#include<math.h>

using namespace std;

void primeFactors(int n);
bool induction(int arr[], int size);
int main() {

	int size = 10;
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int n = 315;

	if (induction(arr, size) == true)
		cout << "Mathematical induction proves the first hypothesis to be true." << endl;
	else
		cout << "Mathematical induction proves the first hypothesis to be false." << endl;

	primeFactors(n);


	return 0;
}

bool induction(int arr[], int size){
	if (((int)pow(arr[0], 3) + (arr[0] * 2)) % 3 == 0)
		return true;
	
	else if ((int)pow(arr[size - 1], 3) + (arr[size - 1] * 2) % 3 == 0)
		induction(arr, size - 1);
	
	else 
		return false;
}

void primeFactors(int n)
{
	while (n % 2 == 0){
		
		cout << 2 << " ";
		n = n / 2;
	}

	for (int i = 3; i <= sqrt(n); i = i + 2)
	{
		while (n % i == 0)
		{
			cout << i << " ";
			n = n / i;
		}
	}

	if (n > 2)
		cout << n << " ";

	cout << endl;
}