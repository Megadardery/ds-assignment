#ifndef CONTACT_MANAGER_H_
#define CONTACT_MANAGER_H_

#include "LinkedList.h"
#include "Contact.h"
#include "Treap.h"  // for Task 2

class ContactManager {
private:
	LinkedList<Contact> contacts;
	Treap<std::string, std::string> tree;  // for Task 2
public:
	ContactManager();
	bool loadFromFile(std::string fileName);
	void add(std::string name, std::string phone_number);
	std::string displayNumber(std::string phone_number);
	friend std::ostream& operator<<(std::ostream& o, ContactManager & c);

	void printTreeFormation(std::ostream& o);
};

#endif  /* CONTACT_MANAGER_H_ */
