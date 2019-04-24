#include "Contact.h"

Contact::Contact()
{
	phone_numbers.delimeter = " - ";
}

Contact::Contact(std::string name) :name(name)
{
	phone_numbers.delimeter = " - ";
}

void Contact::addPhoneNumber(std::string number)
{
	phone_numbers.addSorted(number);
}

std::string Contact::getName()
{
	return name;
}

bool Contact::operator<(const Contact & c)
{
	return name < c.name;
}

bool Contact::operator==(const Contact & c)
{
	return name == c.name;
}
bool Contact::operator!=(const Contact & c) {
	return !(*this == c);
}

std::ostream & operator<<(std::ostream & o, Contact & c)
{
	return o << c.name << " : " << c.phone_numbers;
}
