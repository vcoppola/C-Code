#include<iostream>
using namespace std;

int main() {

	int n;
	int even1 = 0, even2 = 0;

	cout << "Please enter a positive integer: ";
	cin >> n;

	int j = 1;
	while (j <= n) {
		even1 += 2;
		cout << even1 << endl;
		j++;
	}
		
		
	for (int i = 1; i <= n; i++) {
		even2 += 2;
		cout << even2 << endl;
	}

	return 0;

}