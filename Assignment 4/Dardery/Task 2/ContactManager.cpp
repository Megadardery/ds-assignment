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
	tree.insert(phone_number, name);

	Contact c(name);
	c.addPhoneNumber(phone_number);
	auto myc = contacts.get(c);
	if (myc == nullptr)
		contacts.addSorted(c);
	else
		myc->value.addPhoneNumber(phone_number);
}

std::string ContactManager::displayNumber(std::string phone_number)
{
	return tree.find(phone_number);
}

void ContactManager::printTreeFormation(std::ostream & o)
{
	o << "\n________________________________________\n\n";
	o << tree;
	o << "\n________________________________________\n\n";
}

std::ostream & operator<<(std::ostream & o, ContactManager & c)
{
	return o << c.contacts;
}
