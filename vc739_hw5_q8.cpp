#include <iostream>
#include<string>
using namespace std;

void anagramCheck(string Str1, string Str2);
int main(){
		
		string inputText1, inputText2;
	
		cout << "Please enter the first string: " << endl;
		getline(cin,inputText1);
	
		cout << "Please enter the second string: " << endl;
		getline(cin,inputText2);
	
		anagramCheck(inputText1, inputText2);


		
		return 0;
	
}
void anagramCheck(string Str1, string Str2) {

	char lowCaseList[] = { "abcdefghijklmnopqrstuvwxyz" };
	char upCaseList[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };

	int alphCount1[26] = { 0 };
	int alphCount2[26] = { 0 };


	int count = Str1.length();
	int count2 = Str2.length();

	if (count == count2) {

		for (int i = 0; i < count; i++) {
			for (int j = 0; j < 26; j++) {
				if ((Str1[i] == lowCaseList[j]) || (Str1[i] == upCaseList[j])) {
					alphCount1[j] += 1;
				}
				if ((Str2[i] == lowCaseList[j]) || (Str2[i] == upCaseList[j])) {
					alphCount2[j] += 1;
				}
			}
		}
		bool identical = true;

		for (int i = 0; i < 26; i++) {
			if (alphCount1[i] != alphCount2[i]) {
				identical = false;
			}
		}

		if (identical) {
			cout << "They are anagrams" << endl;
		}
		else {
			cout << "They are not anagrams" << endl;
		}
	}
	else {
		cout << "They are not anagrams" << endl;
	}
}