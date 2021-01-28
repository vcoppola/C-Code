#include<iostream>
#include<cmath>
using namespace std;

bool isPerfect(int num);
void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
int main() {

	int n;
	int count = 0;
	int sum = 0;
	int count2 = 0;
	int sum2 = 0;

	cout << "Please	enter a positive integer (>= 2): ";
	cin >> n;

	//cout << n << " " << count << " " << sum;
	analyzeDividors(n, count, sum);
	//cout << endl << n << " " << "count: " << count << " "<< "sum: "<< sum <<endl;


	cout << "Perfect numbers: ";

	//perfect
	for (int i = 2; i < n; i++) {
		if (isPerfect(i) == true) {
			cout << i << " ";
		}
	}
	cout << endl;

	
	int i = 2; 
	int j =	n;
	
	//amicable
	for (i; i <= n; i++) {
		//cout << "Entire range of i: " << i << endl;
		analyzeDividors(i, count, sum);
		//cout << "sum1: " << sum << endl;
		for (j; j >= 2; j--) {
			//cout << "Entire range of j: " << i << endl;
			analyzeDividors(j, count2, sum2);
			//cout << " sum2: " << sum2 << endl;
			if ((sum == j && sum2 == i) && (i != j)) 
				//cout << sum << " " << sum2 << endl;
				cout << i << " and " << j << " are amicable." << endl;			
		
			
		}
		count = 0;
		sum = 0;
		count2 = 0;
		sum2 = 0;
	}

	cout << "No amicable numbers are found in the given range." << endl;
	//out << endl << "count: " << count << " " << "sum: " << sum << endl;
	
	return 0;
}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs){

	int i, j;

	double square_root = sqrt(num);
	for (i = 1; i <= square_root; i++) {
		if (num % i == 0){
			//cout << "factor i: " << i << " " << endl;
			j = i;
			outCountDivs++;
			outSumDivs += i;
			//cout << i << " " << outCOuntDivs << " " << outSumDivs << endl;
		}
	}
	for (j; j > 0; j--) {
		if (j != square_root && num % j == 0){
			int divisor = num / j;
			//cout << "factor j: " << divisor << " " << endl;
			outCountDivs++;
			outSumDivs = outSumDivs + divisor;
			//cout << j << " " << outSumDivs << endl;
		}
	}
	outCountDivs = outCountDivs - 1;
	outSumDivs = outSumDivs - num;
	//cout << outSumDivs << endl;
	//cout << "Sum" << outSumDivs << endl;
}

bool isPerfect(int num) {

	int i, j;
	int count = 0;
	int sum = 0;

	double square_root = sqrt(num);
	for (i = 1; i <= square_root; i++) {
		if (num % i == 0) {
			j = i;
			sum += i;
		}
	}
	for (j; j > 0; j--) {
		if (j != square_root && num % j == 0) {
			int divisor = num / j;
			sum = sum + divisor;
		}
	}

	sum = sum - num;

	if (sum == num)
		return true;
	else
		return false;

}