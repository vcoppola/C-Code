#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;


int main() {

	string inputText;
	int length = 0;

	cout << "Please enter a line of text: " << endl;
	getline(cin, inputText);

	
	length = inputText.length();

	for (int i = 0; i < length + 1; i++) {

		if ((isdigit(inputText[i])) && (((isalpha(inputText[i - 1])) || (isalpha(inputText[i + 1]))) || (inputText[i+1] == ' ' && isalpha(inputText[i+1])))) {// && (inputText[i - 1] = ' ') || (isdigit(inputText[i - 1]))) {
			inputText[i] = inputText[i];
		}
		else
			if (isdigit(inputText[i])) {
				inputText[i] = 'x';
				//		cout << i << endl;
			}

		//if (isdigit(inputText[i])) {
		//if ((i != 0) && isdigit(inputText[i]) && (inputText[i - 1] == ' ') && (inputText[i + 1] == ' ')) {

			//inputText[i] = 'x';
			//cout << inputText[i];


	}
	
	cout << inputText << endl;

	return 0;

}