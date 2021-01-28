#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string str);
int main() {

	string word;

	cout << "Please enter a word: ";
	getline(cin, word);

	if (isPalindrome(word) == true) {
		cout << word << " is a palindrome" << endl;
	}
	else
		cout << word << " is not a palindrome" << endl;

	return 0;
}

bool isPalindrome(string str) {

	int i = 0;                // first characters
	int j = str.length() - 1; // last character

	while (i < j) {
		if (str[i] != str[j]) {
			return false;
		}
		i++;
		j--;
	}

	return true;
}