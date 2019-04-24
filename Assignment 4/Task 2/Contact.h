#ifndef CONTACT_H_
#define CONTACT_H_

#include "LinkedList.h"
#include <string>
#include <iostream>

class Contact {
private:
	std::string name;
	LinkedList<std::string> phone_numbers;
public:
	Contact();
	Contact(std::string name);
	void addPhoneNumber(std::string number);
	std::string getName();
	bool operator<(const Contact & c);
	bool operator==(const Contact & c);
	bool operator!=(const Contact & c);
	friend std::ostream& operator<<(std::ostream& o, Contact & c);
};

#endif  /* CONTACT_H_ */
