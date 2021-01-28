#include<iostream>
using namespace std;

int main() {
	
	int n; 
	int i = 1;
	int ones = 0;
	int tens = 0;
	int hundreds = 0; 
	int thousands = 0;
	int odd = 0;
	int even = 0;

	cout << "Please enter a positive integer: " << endl;
	cin >> n;

	for (int i = 1; i <= n; i++) {

		ones = i % 10;
		tens = i / 10;
		hundreds = i / 100;
		thousands = i / 1000;
		
		if (ones == 2 || ones == 4 || ones == 6 || ones == 8)
			even = even + 1;
		else
			if (ones == 1 || ones == 3 || ones == 5 || ones == 7 || ones ==9)
				odd = odd + 1;

		if (tens == 2 || tens == 4 ||  tens == 6 || tens == 8)
			even = even + 1;
		else
			if (tens == 1 || tens == 3 || tens == 5 || tens == 7 || tens == 9)
				odd = odd + 1;


		if (thousands == 2 || thousands == 4 || thousands == 6 || thousands == 8)
			even = even + 1;
		else
			if (thousands == 1 || thousands == 3 || thousands == 5 || thousands == 7 || thousands == 9)
				odd = odd + 1;

		if (even > odd)
			cout << i << endl; 

		even = 0;
		odd = 0;
	}

	return 0;

}
