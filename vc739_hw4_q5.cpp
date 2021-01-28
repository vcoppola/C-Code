#include<iostream>
#include<cmath>
using namespace std;

void printDivisors(int num);
int main() {

	int n;

	cout << "Please	enter a positive integer (>= 2): ";
	cin >> n;

	printDivisors(n);

	return 0;
}

void printDivisors(int num) {

	int i, j;

	double square_root = sqrt(num);
	for (i = 1; i <= square_root; i++) {
		if (num % i == 0)
			cout << i << " ";
		j = i;
	}
	for (j; j > 0; j--) {
		if (j != square_root && num % j == 0)
			cout << num / j << " ";
	}

	cout << endl;

}