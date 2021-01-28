#include<iostream>

using namespace std;

int main() {
	 
	int decimal, remainder, binary;
	int i = 1;
	int binOut = 0;

	cout << "Enter a decimal number: " << endl;
	cin >> decimal;

	binary = decimal;
	
	cout << "The binary representation of " << decimal << " is ";
	
	if (decimal <= 1)
		cout << decimal;
	
	else
		while (binary != 0) {
			remainder = binary % 2;
			binary = binary / 2;
			binOut = binOut + (remainder * i);
			i = i * 10;
		}
	cout << binOut << endl;
	return 0;
}