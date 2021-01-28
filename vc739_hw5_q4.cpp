#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>
using namespace std;

void checkPin(string pass, int num);
int main() {

	int num = 1;
	srand(time(0));
	num = abs(rand() * 1000000000);
	string pin = "0123456789";
	string pass;

	cout << "Please enter your PIN according to the following mapping: " << endl;
	cout << "PIN:    " << pin << endl;
	cout << "NUM:    " << num << endl;
	getline(cin, pass);

	checkPin(pass, num);

	return 0;
}

void checkPin(string pass, int num) {

	string number;
	number = to_string(num);

	if ((number.substr(1, 1)) == (pass.substr(0, 1)) &&
		(number.substr(2, 1)) == (pass.substr(1, 1)) &&
		(number.substr(3, 1)) == (pass.substr(2, 1)) &&
		(number.substr(4, 1)) == (pass.substr(3, 1)) &&
		(number.substr(5, 1)) == (pass.substr(4, 1))) {
		cout << "Your PIN is correct" << endl;
	}
	else {
		cout << "Your PIN is not correct" << endl;
	}

}