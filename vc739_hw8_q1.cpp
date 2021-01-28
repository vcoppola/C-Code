#include <iostream>
#include <string>
#include <vector>

using namespace std;

int digit_to_int(char c);

class Money {
public:
	friend Money operator +(const Money& amount1, const Money& amount2);
	friend Money operator -(const Money& amount1, const Money& amount2);
	friend Money operator -(const Money& amount);
	friend bool operator ==(const Money& amount1, const Money& amount2);
	friend bool operator <(const Money& amount1, const Money& amount2);
	Money(long dollars, int cents);
	Money(long dollars);
	Money();
	double get_value() const;
	friend istream& operator >>(istream& ins, Money& amount);
	friend ostream& operator <<(ostream& outs, const Money& amount);

private:
	long all_cents;
};

Money operator +(const Money& amount1, const Money& amount2) {
	Money temp;
	temp.all_cents = amount1.all_cents + amount2.all_cents;
	return temp;
}

bool operator ==(const Money& amount1, const Money& amount2){
	return(amount1.all_cents == amount2.all_cents);
}

Money operator -(const Money& amount1, const Money& amount2){
	Money temp;
	temp.all_cents = amount1.all_cents - amount2.all_cents;
	return temp;
}

Money operator -(const Money& amount) {
	Money temp;
	temp.all_cents = -amount.all_cents;
	return temp;
}

istream& operator >> (istream& ins, Money& amount) {
	char one_char, decimal_point, digit1, digit2;
	long dollars;
	int cents;
	bool negative;
	ins >> one_char;

	if (one_char == '-') {
		negative = true;
		ins >> one_char;
	}
	else {
		negative = false;
	}

	ins >> dollars >> decimal_point >> digit1 >> digit2;
	
	if (one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2)) {
		cout << " Error illegal form of money input" << endl;
		exit(1);
	}

	cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);
	amount.all_cents = dollars * 100 + cents;

	if (negative) {
		amount.all_cents = -amount.all_cents;
	}

	return ins;
}

int digit_to_int(char c) {
	return(static_cast<int>(c) - static_cast <int>('0'));
}

bool operator <(const Money& amount1, const Money& amount2){
	return(amount1.all_cents < amount2.all_cents);
}

ostream& operator <<(ostream& outs, const Money& amount) {
	long positive_cents, dollars, cents;
	positive_cents = labs(amount.all_cents);
	dollars = positive_cents / 100;
	cents = positive_cents % 100;
	if (amount.all_cents < 0) {
		outs << "-$" << dollars << '.';
	}
	else {
		outs << "$" << dollars << '.';
	}

	if (cents < 10) {
		outs << '0';
		outs << cents;
		return outs;
	}
}

//Constructors
Money::Money(long dollars, int cents) {
	if (dollars * cents < 0) {
		cout << "Illegal values for dollars and cents" << endl;
		exit(1);
	}
	all_cents = dollars * 100 + cents;
}

Money::Money(long dollars) : all_cents(dollars * 100) {
}

Money::Money() : all_cents(0) {
}

double Money::get_value() const {
	return(all_cents * 0.01);
}

class Check {
public:
	Check();
	Check(string chkNo, Money chkAmt, bool chkCashd);
	void setNumber(string no);
	void setAmount(Money amt);
	void setCashed(bool cashd);
	string getNumber();
	Money getAmount();
	bool getCashed();
	friend istream& operator >> (istream& ins, Check& chk);
	friend ostream& operator <<(ostream& outs, const Check& chkinfo);

private:
	string number;
	Money amount; //Check is a class which uses class Money
	bool cashed; //Check cased or not
};

//Constructors
Check::Check():number(""), amount(), cashed(false) {
}

Check::Check(string chkNo, Money chkAmt, bool chkCashd) {
	this->number = chkNo;
	this->amount = chkAmt;
	this->cashed = chkCashd;
}

//Accessor and mutator functions

void Check::setNumber(string no) {
	this->number = no;
}

void Check::setAmount(Money amt) {
	this->amount = amt;
}

void Check::setCashed(bool cashd) {
	this->cashed = cashd;
}

string Check::getNumber() {
	return this->number;
}

Money Check::getAmount() {
	return this->amount;
}

bool Check::getCashed() {
	return this->cashed;
}

istream& operator >> (istream& ins, Check& chk) {
	int cashd;
	string no;
	Money amt;

	while (!(ins >> no) || !(ins >> amt) || !(ins >> cashd)) {
		ins.clear();
		cin.ignore(80, '\n');
		cout << "Error illegal form of input for Check. Try again" << endl;
	}

	cin.ignore(80, '\n');
	chk.number = no;
	chk.amount = amt;
	chk.cashed = cashd;
	return ins;
}
ostream& operator <<(ostream& outs, const Check& chkinfo) {
	outs << "Check No: ";
	if (chkinfo.cashed) {
		outs << "Cashed";
	}
	else {
		outs << "Not Chased";
		return outs;
	}
}

///Main Program

const int SIZE = 10;
void sort(int a[], int number_used);
void swap_values(int & v1, int & v2);
int index_of_smallest(const int a[], int start_index, int number_used);

int main() {

	Check checks[SIZE];
	int count = 0, k = 0, j = 0;
	double initBal, finalBal, deposit, CheckAmts = 0, depositAmts = 0, checkCashedAmts = 0;
	double deposits[SIZE];
	char ans;
	vector<string> uncashedChecks;
	vector<string> cashedChecks;

	cout << "Enter the initial account balance: " << endl;
	cin >> initBal;

	cout << "Enter deposit amount (max 5, -1 to stop) " << endl;
	cin >> deposit;

	while (deposit != -1 && count) {
		deposits[count] = deposit;
		count++;
		cin >> deposit;
	}

	for (int i = 0; i;) {
		initBal = initBal + deposits[i];
		depositAmts = depositAmts + deposits[i];
	}

	count = 0;

	do {
		cout << "Enter the check details (number, amount cashed/not cashed (1/0)): " << endl;
		cin >> checks[count];
		cout << "Would you like to enter another check's details? (y/n/): " << endl;
		cin >> ans;
		count++;


		while (ans == 'y' || ans == 'Y') {
			for (int i = 0; i;) {
				double value = (checks[i].getAmount()).get_value();
				if (checks[i].getCashed()) {
					initBal = initBal - value;
					checkCashedAmts = checkCashedAmts + value;
					cashedChecks.push_back(checks[i].getNumber());
				}
				else if (checks[i].getNumber() != "") {
					uncashedChecks.push_back(checks[i].getNumber());
					CheckAmts = CheckAmts + value;
				}

				sort(uncashedChecks.begin(), uncashedChecks.end());
				sort(cashedChecks.begin(), cashedChecks.end());


				cout << "\n The final balance is $" <
					cout << "The total amount of all deposts made: $" <
					cout << "The total amount of all checks: $" <
					cout << "The total amount of all checks cashed: $" < ;

				if (cashedChecks.size() > 0) {
					cout << " The sorted list of cashed checks is: ";

					for (int i = 0; i;) {
						cout < 
						cout < 
					}
				}

				if (uncashedChecks.size() > 0) {
					cout << " The sorted list of Uncashed checks is: ";
					for (int i = 0; i;) {
						cout < ;
						cout < ;
					}
				}
			}

		}
		
	}
	return 0;
}
