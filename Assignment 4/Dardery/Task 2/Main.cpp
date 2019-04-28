#include <iostream>
#include "ContactManager.h"

using namespace std;


int main() {
	ContactManager d;
	d.loadFromFile("all-contacts.in");
	cout << d;
	cout << "----------------------------------------------\n";
	while (true) {
		string phone_number;
		cout << "Enter phone number: ";
		cin >> phone_number;
		if (phone_number == "done") break;
		cout << d.displayNumber(phone_number) << "\n";
	}
	d.printTreeFormation(cout);
}