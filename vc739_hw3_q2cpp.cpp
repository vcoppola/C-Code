#include<iostream>
using namespace std;

int main() {
	
	int num, j, m, d, c, l, x, v, i;
	cout << "Enter a decimal number: ";
	cin >> num;
	cout << num << " " << "is ";

		m = num / 1000;
		num = num % 1000;

		d = num / 500;
		num = num % 500;

		c = num / 100;
		num = num % 100;

		l = num / 50;
		num = num % 50;

		x = num / 10;
		num = num % 10;

		v = num / 5;
		num = num % 5;

		i = num;

		

		for (j = 1; j <= m; j++)
			cout << "M";

		for (j = 1; j <= d && j <=1; j++)
			cout << "D";

		for (j = 1; j <= c; j++)
			cout << "C";

		for (j = 1; j <= l && j<= 1; j++)
			cout << "L";

		for (j = 1; j <= x; j++)
			cout << "X";

		for (j = 1; j <= v && j <=1 ; j++)
			cout << "V";
		
		for (j = 1; j <= i; j++)
			cout << "I";


		cout << endl;

		return 0;
}






