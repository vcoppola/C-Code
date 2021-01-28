#include <iostream>
#include <string>

using namespace std;

int main() {
	int weight, height;
	string status;

	cout << "Please enter weight (in pounds): ";
	cin >> weight;
	cout << "Please enter height (in inches): ";
	cin >> height;

	double bmiWeight = weight * .453592;
	double bmiHeight = height * .0254;

	double BMI = bmiWeight / pow(bmiHeight, 2);

	if (BMI < 18.5)
		status = "Underweight";
	else if (BMI >= 18.5 &&  BMI < 25)
		status = "Normal";
	else if (BMI >= 25 && BMI < 30)
		status = "Overweight";
	else
		status = "Obese";
	
	cout << "The weight status is " << status << endl;
	
	return 0;

}