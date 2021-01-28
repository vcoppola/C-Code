#include<iostream>
#include <string>
using namespace std;

bool isLeapYear(int year);
void printYearCalender(int year, int startingDay);
int printMonthCalender(int numOfDays, int startingDay);
int main() {

	int day, totalDays;

	cout << "Enter the first day of the month:" << endl;
	cout << "Monday = 1" << endl;
	cout << "Tuesday = 2" << endl; 
	cout << "Wednesday = 3" << endl; 
	cout << "Thursday = 4" << endl; 
	cout << "Friday = 5" << endl;
	cout << "Saturday = 6" << endl;
	cout << "Sunday = 7" << endl;
	cout << "Day: ";
	cin >> day;

	cout << "Enter total number of days in this month:" << endl;
	cin >> totalDays;

	cout <<  endl << "\tMon\tTues\tWed\tThr\tFri\tSat\tSun" << endl;

	int lastDay = printMonthCalender(totalDays, day);
	
	cout << endl << endl << "The last day of the month is day " << lastDay << endl;


	int year, day2;
	
	cout << endl << "Enter a year to print out a calendar:" << endl;
	cin >> year;
	cout << "Enter the first day to start the year with:" << endl;
	cout << "Monday = 1" << endl;
	cout << "Tuesday = 2" << endl;
	cout << "Wednesday = 3" << endl;
	cout << "Thursday = 4" << endl;
	cout << "Friday = 5" << endl;
	cout << "Saturday = 6" << endl;
	cout << "Sunday = 7" << endl;
	cout << "Day: ";
	cin >> day2;
		
	printYearCalender(year, day2);

	return 0;
	}

int printMonthCalender(int numOfDays, int startingDay) {

	int totalWeeks = numOfDays / 7;
	int i = 1;
	int date = 1;
	int dayQueue = 0;

	cout << "\t";

	for (i; i < startingDay; i++) {
		cout << "*\t";
		dayQueue++;
	}

	int week = 0;
	for (date; date <= numOfDays; date++) {
		cout << date << "\t";
		dayQueue++;

		if (dayQueue % 7 == 0 && week <= totalWeeks) {
			cout << endl;
			cout << "\t";
			week++;
		}
	}

	cout << endl;

	if ((startingDay == 1 || startingDay == 2 || startingDay == 3 || startingDay == 4 || startingDay == 5 || startingDay == 6 || startingDay == 7) && numOfDays == 29)
		return startingDay;
	else
		if ((startingDay == 2 || startingDay == 3 || startingDay == 4 || startingDay == 5 || startingDay == 6 || startingDay == 7) && numOfDays == 28)
			return (startingDay - 1);
		else
			if ((startingDay == 2 || startingDay == 3 || startingDay == 4 || startingDay == 5 || startingDay == 6) && numOfDays == 30)
				return (startingDay + 1);
			else
				if ((startingDay == 2 || startingDay == 3 || startingDay == 4 || startingDay == 5) && numOfDays == 31)
					return (startingDay + 2);
				else
					if ((startingDay == 6) && numOfDays == 31)
						return 1;
					else
						if (startingDay == 1 && numOfDays == 28)
							return 7;
						else
							if (startingDay == 1 && numOfDays == 30)
								return 2;
							else
								if (startingDay == 1 && numOfDays == 31)
									return 3;
								else
									if (startingDay == 7 && numOfDays == 30)
										return 1;
									else
										if (startingDay == 7 && numOfDays == 31)
											return 2;
}

void printYearCalender(int year, int startingDay) {

	int February, month, numOfDays;
	string header;

	if (isLeapYear(year) == true)
		February = 29;
	else
		February = 28;


	for (month = 1; month <= 12; month++) {
		if (month == 1) {
			numOfDays = 31;
			header = "January ";
		}
		else
			if (month == 2 && February == 29) {
				numOfDays = 29;
				header = "February ";
			}
			else
				if (month == 2 && February == 28) {
					numOfDays = 28;
					header = "February ";
				}
				else
					if (month == 3) {
						numOfDays = 31;
						header = "March ";
					}
					else
						if (month == 4) {
							numOfDays = 30;
							header = "April ";
						}
						else
							if (month == 5) {
								numOfDays = 31;
								header = "May ";
							}
							else
								if (month == 6) {
									numOfDays = 30;
									header = "June ";
								}
								else
									if (month == 7) {
										numOfDays = 31;
										header = "July ";
									}
									else
										if (month == 8) {
											numOfDays = 30;
											header = "August ";
										}
										else
											if (month == 9) {
												numOfDays = 30;
												header = "September ";
											}
											else
												if (month == 10) {
													numOfDays = 31;
													header = "October ";
												}
												else
													if (month == 11) {
														numOfDays = 30;
														header = "November ";
													}
													else
														if (month == 12) {
															numOfDays = 31;
															header = "December ";
														}
		int i = 1;
		int date = 1;
		int dayQueue = 0;

		int totalWeeks = numOfDays / 7;

		cout << "\t" << header << year;
		cout << "\t";

		cout << endl << "\tMon\tTues\tWed\tThr\tFri\tSat\tSun" << endl;
		cout << "\t";

		for (i; i < startingDay; i++) {
			cout << "*\t";
			dayQueue++;
		}

		int week = 0;
		for (date; date <= numOfDays; date++) {
			cout << date << "\t";
			dayQueue++;

			if (dayQueue % 7 == 0 && week <= totalWeeks) {
				cout << endl;
				cout << "\t";
				week++;
			}
		}

		cout << endl << endl;


		if ((startingDay == 1 || startingDay == 2 || startingDay == 3 || startingDay == 4 || startingDay == 5 || startingDay == 6 ) && numOfDays == 29)
			startingDay = startingDay + 1;
		else
			if ((startingDay == 2 || startingDay == 3 || startingDay == 4 || startingDay == 5 || startingDay == 6 || startingDay == 7) && numOfDays == 28)
				startingDay = startingDay;
			else
				if ((startingDay == 2 || startingDay == 3 || startingDay == 4 || startingDay == 5) && numOfDays == 30)
					startingDay = startingDay + 2;
				else
					if ((startingDay == 2 || startingDay == 3 || startingDay == 4) && numOfDays == 31)
						startingDay = startingDay + 3;
					else
						if ((startingDay == 6) && numOfDays == 31)
							startingDay = 2;
						else
							if (startingDay == 1 && numOfDays == 28 || startingDay == 7 && numOfDays == 29 || startingDay == 6 && numOfDays == 30 || startingDay == 5 && numOfDays == 31 )
								startingDay = 1;
							else
								if (startingDay == 1 && numOfDays == 30)
									startingDay = 3;
								else
									if (startingDay == 1 && numOfDays == 31)
										startingDay = 4;
									else
										if (startingDay == 7 && numOfDays == 30)
											startingDay = 2;
										else
											if (startingDay == 7 && numOfDays == 31)
												startingDay = 3;

	}
}


bool isLeapYear(int year) {

	int num1 = year % 4;
	int num2 = year % 100;
	int num3 = year % 400;

	if (num1 == 0 && num2 != 0 || num1 == 0 && num3 == 0)
		return true;
	else
		return false;
}


