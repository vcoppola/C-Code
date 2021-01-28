#include<iostream>
using namespace std;

int main() {

	int n;

	cout << "Please enter a positive integer :" << endl;
	cin >> n;

	//reverse triangle
	int line = 1;
	int asterixQueue = 0;

	//line
	for (line; line <= n; line++) {
		//set asterix
		if (line == 1)
			asterixQueue = (n + (n - 1));
		else
			asterixQueue = asterixQueue - 2;
		//space
		for (int space=0; space < line; space++) {
			cout << ' ';
		}
		//asterix
		for (int asterix = 1; asterix <= asterixQueue; asterix++) {
				cout << '*';
		}
	
		cout << endl;
	}

	//triangle
	int spaceQueue = 0;

	//line
	for (line; line <= (2*n); line++) {
		//cout << line << endl;
		//set asterix
		if (line == (n + 1)) {
			asterixQueue = 0;
			spaceQueue = n - 1;
		}
		else {
			asterixQueue = asterixQueue + 2;
			spaceQueue = spaceQueue - 1;
		}
		//space
		for (int space = 0; space <= spaceQueue; space++) {
			cout << ' ';
		}
		//asterix
		for (int asterix = 0; asterix <= asterixQueue; asterix++) {
			cout << '*';
		}

		cout << endl;
	}

	return 0;
}