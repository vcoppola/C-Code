#include<iostream>
using namespace std;

void printShiftedTriangle(int n, int m, char symbol);
void printPineTree(int n, char m);
int main() {

	int trees, tree2, offset;
	char symbol, symbol2;

	cout << "Please enter a positive integer for the number of triangles in a tree:" << endl;
	cin >> trees;
	cout << "Please enter a character for tree construction:" << endl;
	cin >> symbol;

	cout << "Please enter a positive integer for the number of lines in a second triangle:" << endl;
	cin >> tree2;
	cout << "Please enter a positive integer indicating the number of spaces you would like to offset the second triangle with: " << endl;
	cin >> offset;
	cout << "Please enter the character you would like to construct the second triangle with:" << endl;
	cin >> symbol2;
	
	printPineTree(trees, symbol);
	printShiftedTriangle(tree2, offset, symbol2);

	return 0;
}


void printPineTree(int trees, char symbol) {

	int treeQueue = 1;
	int symbolQueue = 1;

	//tree 
	for (treeQueue; treeQueue < trees + 1; treeQueue++)	{
		int line = 1;
		int spaceQueue = trees;

		//line
		for (line; line <= treeQueue + 1; line++) {
			if (treeQueue == 1 && line == 1) {
				spaceQueue = trees - 1;
			}

			else {
				symbolQueue = symbolQueue + 2;
				spaceQueue = spaceQueue - 1;
			}

			//space printing
		for (int space = 0; space <= spaceQueue; space++) {
			cout << ' ';
			}

			//char printing
			if (line == 1)
				for (int symbolQueue = 1; symbolQueue <= line; symbolQueue++) {
					cout << symbol;
					}
			else
				for (int symbolQueue = 1; symbolQueue <= line + (line - 1); symbolQueue++) {
					cout << symbol;
					}
		cout << endl;
		}
	}

}

void printShiftedTriangle(int n, int m, char symbol) {

	//triangle
	int spaceQueue = 0;
	int line = 1;
	int symbolQueue = 0;

	//line
	for (line; line <= n; line++) {
		if (line == 1) {
			spaceQueue = m + (n - 1);
		}
		else {
			symbolQueue = symbolQueue + 2;
			spaceQueue = spaceQueue - 1;
		}
		
		//space
		for (int space = 0; space <= spaceQueue; space++) {
			cout << ' ';
		}
		
		//symbol
		for (int sym = 0; sym <= symbolQueue; sym++) {
			cout << symbol;
		}

		cout << endl;
	}

}