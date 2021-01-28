#include<iostream>
using namespace std;

int fib(int n);
int main() {
	int num, fibNum;

	cout << "Please enter a positive integer: ";
	cin >> num;

	fibNum = fib(num);

	cout << fibNum << endl;

	return 0;
}

int fib(int n) {
	
	int firstNum = 1; 
	int secondNum = 1; 
	int nextNum;
	int count = 0;

	for (int i = 1; i <= n-2; i++) {
			nextNum = firstNum + secondNum;
			//cout << firstNum << secondNum << nextNum << endl;
			firstNum = secondNum;
			secondNum = nextNum;
			//cout << firstNum << secondNum << nextNum << sum <<endl;
		}

	return nextNum;
}
