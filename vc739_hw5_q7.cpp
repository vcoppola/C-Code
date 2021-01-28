#include<iostream>
#include <string>
using namespace std;

void wordLetterCount(string Str);
int main(){
	
	string inputText;
	
	cout << "Please enter a line of text: " << endl;
	getline(cin, inputText);

	wordLetterCount(inputText);

	return 0;
}
void wordLetterCount(string Str) {

	int letters[26];
	int wordCount = 1;
	int i = 0;

	for (i = 0; i < 26; i++)
		letters[i] = 0;
	i = 0;

	while (Str[i] != '\0') {
		if (Str[i] == ' ')
			wordCount++;
		letters[tolower(Str[i]) - 97]++;
		i++;
	}

	cout << wordCount << " words" << endl;

	for (i = 0; i < 26; i++)
	{
		if (letters[i] > 0)
			cout << letters[i] << " " << static_cast<char>(i + 97) << endl;
	}

}