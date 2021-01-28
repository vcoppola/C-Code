#include<iostream>
#include<string>
using namespace std;

int main() {

	string firstName;
	string middle;
	string lastName;

	string middleInitial;

	cout << "Input your first name, middle name (or initial) and last name separated by spaces: " << endl;
	cin >> firstName >> middle >> lastName;

	middleInitial = middle.substr(0, 1);


	cout << lastName << ", " << firstName << " " << middleInitial << ". " << endl;

	return 0;

}