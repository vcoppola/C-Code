#include<iostream>
#include<cmath>
using namespace std;

int main() {
	

	int n;
	
	cout << "Please enter a value for n:" << endl;
	cin >> n;

	double theta = (5 * pow(n, 3)) + (2 * pow(n, 2)) + (3 * n);
	cout << "Demonstrating proof a, Theta(n^3) = "<< theta << endl << endl;

	double theta2 = (7 * pow(n, 2)) + (2 * n) - 8;
	cout << "Demonstrating proof b, Theta(n) = " << theta2 << endl << endl;

	return 0;
}