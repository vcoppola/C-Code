#include <iostream>
#include <math.h>

using namespace std;

int main() {

	const int FLOOR_ROUND = 1;
	const int CEILING_ROUND = 2;
	const int ROUND = 3;

	double num, result;
	int method;

	cout << "Please enter a Real number:" << endl;
	cin >> num;
	cout << "Choose your rounding method:" << endl << "1. Floor round" << endl << "2. Ceiling round" << endl << "3. Round to the nearest whole number" << endl;
	cin >> method;
	
	switch (method) {
	case FLOOR_ROUND:
		result = floor(num);
		break;
	case CEILING_ROUND:
		result = ceil(num);
		break;
	case ROUND:
		result = round(num);
		break;
	default:
		cout << "Illegal expression" << endl;
		break;
	}

	cout << result << endl;

	return 0;

}