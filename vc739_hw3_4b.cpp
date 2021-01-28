#include<iostream>
#include<cmath>
using namespace std;

int main() {

	int count;
	float num, product, mean;

	cout << "Please enter a non-empty sequence of positive integers, each one in a separate	line. End your sequence by typing - 1:" << endl;

	num = 0;
	count = 0;
	product = 1;

	while (num != -1) {
		cin >> num;
		if (num != -1)
			product *= num;
			count++;
	}

	count = count - 1;
	mean = pow(product, 1 / (float)count);
	cout << "The geometric mean is: " << mean << endl;

	return 0;
}
