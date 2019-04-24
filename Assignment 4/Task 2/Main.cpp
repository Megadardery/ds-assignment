#include <iostream>
#include "ContactManager.h"

using namespace std;
int main() {
	ContactManager d;
	d.loadFromFile("all-contacts.in");
	cout << d;
}