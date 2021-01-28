#include <iostream>

using namespace std;

int main() {

	float priceFirst, priceSecond, taxInput;
	char clubCard;

	cout << "Enter the price of the first item: ";
	cin >> priceFirst;
	cout << "Enter the price of the second item: ";
	cin >> priceSecond;
	cout << "Does the customer have a club card? (Y/N): ";
	cin >> clubCard;
	cout << "Enter tax rate, e.g 5.5 for 5.5% tax: ";
	cin >> taxInput;

	float basePrice = priceFirst + priceSecond;
	double clubDiscounted, halfPrice;

	if (priceFirst < priceSecond){
		halfPrice = (.5 * priceFirst) + priceSecond;
	}
	else {
		halfPrice = (.5 * priceSecond) + priceFirst;
	}

	if (clubCard == 'y' || clubCard == 'Y') {
		clubDiscounted = halfPrice * .10;
	}
	else if (clubCard == 'n' || clubCard == 'N') {
		clubDiscounted = 0;
	}

	double afterDiscount = halfPrice - clubDiscounted;
	double taxRate = taxInput * .01;
	double totalPrice = afterDiscount + (afterDiscount * taxRate);

	cout << "Base price: " << basePrice << endl;
	cout << "Price after discounts: " << afterDiscount  << endl;
	cout << "Total price: " << totalPrice << endl;

	return 0;
}