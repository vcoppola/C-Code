#include <iostream>
using namespace std;

int main() {

	int n;

	cout << "Please enter a positive integer:" << endl;
	cin >> n;

	for (int y = 1; y <= n; y++) {
		cout << " ";
		for (int x = 1; x <= n; x++) {
			cout << x*y << " ";
			if (x * y <= 99)
				cout << " ";
			if (x * y <= 9)
				cout << " ";
		}
		cout << endl << endl;
	}
	return 0;

}