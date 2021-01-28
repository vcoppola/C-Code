#include<iostream>
#include<math.h>
using namespace std;

void printRuler(int n);
void printOppositeTriangles(int n);
void printTriangle(int n);
int main() {
	int x = 4;

	printTriangle(x);
	cout << endl;
	printOppositeTriangles(x);
	cout << endl;
	printRuler(x);

	return 0;

}
void printTriangle(int n)
{
	if (n == 1){
		cout << "*" << endl;
	}
	else{
		printTriangle(n - 1);
		for (int i = 0; i < n; i++){
			cout << "*";
		}
	cout << endl;
	}
}

void printOppositeTriangles(int n) {
	if (n == 0)
		return;
	else {
		for (int i = 0; i < n; i++) {
			cout << "*";
		}
		cout << endl;
		printOppositeTriangles(n - 1);
	}

	if (n == 1) {
		cout << "*" << endl;
	}
	else {
		for (int i = 0; i < n; i++) {
			cout << "*";
		}
		cout << endl;
	}
}
void printRuler(int n) {

	if (n == 1){
		cout << "-" << endl;
	}
	
	else {
		// n - 1 % 2 > 0		
		for (int i = 0; i < n; i++) {
			if (i == n / 2) {
				cout << "----";
				//if (i % 2 == 0)
				cout << endl;
			}
			else
				cout << '-';
				cout << endl;
		}
		//printRuler(n - 1);
		//cout << endl;
	}
}


//	Total Lines
//		cout << (pow(2, n) - 1);



