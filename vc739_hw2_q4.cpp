#include <iostream>
#include <cmath>

using namespace std;

int main() {

	double a, b, c;

	cout << "Please enter value of a: ";
	cin >> a;
	cout << "Please enter value of b: ";
	cin >> b;
	cout << "Please enter value of c: ";
	cin >> c;

	double discriminant = (pow(b, 2) - 4 * a * c);
	double root1 = (((-b) + sqrt(discriminant)) / (2 * a));
	double root2 = (((-b) - sqrt(discriminant)) / (2 * a));

	//cout << discriminant << endl;
	//cout << root1 << endl;
	//cout << root2 << endl;
	
	// if discr negative, 0 solutions
	// if discr 0,  1 solution
	// if discr positive, 2 solutions

	if (discriminant == 0)
	{
		cout << "The equation has a single real solution x=" << root1 << endl;
	}
	else if (discriminant < 0)
	{
		cout << "The equation has no real solutions" << endl;
	}
	else
	{
		cout << "The equation has two real solutions x=" << root1 << " x=" << root2 << endl;
	}

   return 0;
}