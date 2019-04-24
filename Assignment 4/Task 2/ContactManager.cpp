#include <iostream>
#include <fstream>
#include <string>
#include "ContactManager.h"
using namespace std;
ContactManager::ContactManager()
{
	contacts.delimeter = "\n";
}

bool ContactManager::loadFromFile(string fileName)
{
	ifstream file(fileName);
	if (!file.is_open()) return false;
	while (file.peek() != EOF) {
		string number;
		string name;
		file >> number;
		file.get();
		getline(file, name);
		
		add(name, number);
		
	}
	return true;

}

void ContactManager::add(string name, string phone_number)
{
	Contact c(name);
	c.addPhoneNumber(phone_number);
	auto myc = contacts.get(c);
	if (myc == nullptr)
		contacts.addSorted(c);
	else
		myc->value.addPhoneNumber(phone_number);
}

void ContactManager::displayNumber(std::string phone_number)
{
	// TODO: insert return statement here
	// This will use treap when implemented
}

std::ostream & operator<<(std::ostream & o, ContactManager & c)
{
	return o << c.contacts;
}
