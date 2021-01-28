#include<iostream>
using namespace std;


double eApprox(int n);
int main() {

	cout.precision(30);
	
	for (int n = 1; n <= 15; n++) {
		cout << "n = " << n << '\t' << eApprox(n) << endl;
	}

	return 0;
}
double eApprox(int n) {
	
	double e = 0.0;
	int i;

	for (i = 15; i > 0; i--) {
		e += 1.0 / n * 1 / (n - 1.0);
	}
	e = e + 1;
	return e;

}