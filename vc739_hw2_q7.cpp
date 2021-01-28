#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main() {

		int hour24, minutes24, minutesCall;
		char temp;
		string day;
		double rate;

		cout << "Enter the start time of the call in military time, e.g. 1:30pm = 13:30: ";
		cin >> hour24 >> temp >> minutes24;
		cout << "Enter the length of the call in minutes: ";
		cin >> minutesCall;
		cout << "Enter the day of the week on which the call started using only the first two letters of the day (Monday = Mo, Tuesday = Tu, etc.): ";
		cin >> day;

		int finalTime = (hour24 * 100) + minutes24;


		if (day == "mo" || day == "Mo" || day == "tu" || day == "Tu" || day == "we" || day == "We" 
			|| day == "th" || day == "Th" || day == "fr" || day == "Fr" ) {
				
			if (finalTime >= 800 && finalTime <= 1800)
				rate = 0.4;
			else
				rate = 0.25;
			}

		else if (day == "sa" || day == "Sa" || day == "su" || day == "Su") {
				
				rate = 0.15;
			}

		double cost = minutesCall * rate;

		cout << "The cost of your call was: $";
		
		printf("%.2f", cost);
		
		cout << endl;

		return 0;
}