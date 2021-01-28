#include <iostream>
using namespace std;

int main() {
	int int1, int2;
	int sum, diff, prod, mod, div2;
	float div1;

	cout << "Please enter two integers separated by a space: " << endl;
	cin >> int1 >> int2;

	float float1 = float(int1);
	float float2 = float(int2);
	sum = int1 + int2;
	diff = int1 - int2;
	prod = int1 * int2;
	div1 = float1 / float2;
	div2 = int1 / int2;
	mod = int1 % int2;


	cout << int1 << " + " << int2 << " = " << sum << endl;
	cout << int1 << " - " << int2 << " = " << diff << endl;
	cout << int1 << " * " << int2 << " = " << prod << endl;
	cout << float1 << " / " << float2 << " = " << div1 << endl;
	cout << int1 << " div " << int2 << " = " << div2 << endl;
	cout << int1 << " mod " << int2 << " = " << mod << endl;

	return 0;
}