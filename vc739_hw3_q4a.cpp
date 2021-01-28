#include<iostream>
#include<cmath>
using namespace std;

int main() {

	int sequence, i;
	float num, product, mean;

	cout << "Please enter the length of the sequence: ";
	cin >> sequence;
	cout << "Please enter your sequence:" << endl;

	product = 1.0;
	for (int i = 1; i <= sequence; i++) {
		cin >> num;
		product *= num;
	}

	mean = pow(product, 1 /(float) sequence);
	cout << "The geometric mean is: " << mean << endl;

	return 0;
}
