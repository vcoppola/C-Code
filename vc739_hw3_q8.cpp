#include<iostream>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	
	int x1, x2, x3, x4;
	int guessNum = 5;
	int lowRange = 1;
	int	highRange = 100;
	int guessInt;

	srand(time(0));
	
	x1 = rand();
	x2 = rand();
	x3 = rand() % 100;
	x4 = (rand() % 100) + 1;

	//cout << x1 << " " << x2 << " " << x3 << " " << x4 << endl;

	cout << "I thought of a number between 1 and 100! Try to guess it." << endl;

	int i = 5, j = 1;

	for (i, j; i <= 5, j <= 5 ; i--, j++) {
		cout << "Range: " << lowRange << ", " << highRange << ", Number of guesses left: " << i << endl;
		cout << "Your guess: ";
		cin >> guessInt;
	
		if (guessInt == x4) {
			cout << "Congrats! You guessed my number in " << j << " guesses." << endl << endl;
			break;
		}
			else
				if (guessInt < x4){
					cout << "Wrong! My number is bigger." << endl << endl;
					lowRange = guessInt + 1;
				}
				else
					if (guessInt > x4) {
						cout << "Wrong! My number is smaller." << endl << endl;
						highRange = guessInt  - 1;
					}

		if (j == 5)
			cout << "Out of guesses. My number is: " << x4 << endl;

		}

		
		return 0;

}