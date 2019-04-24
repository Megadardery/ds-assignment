#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#include <iostream>
#include<string>
template<class T>
class LinkedList {
public:
	class Node {
	public:
		T value;
		Node* next;

		Node(T v);
	};
private:
	Node* head;
public:
	std::string delimeter; // optional: just for printing

	LinkedList();
	Node* addSorted(T v);
	Node* get(T v);

	// operator overloading for printing
	template<class U>
	friend std::ostream& operator<<(std::ostream& o, LinkedList<U> & c);
};

template<class T>
LinkedList<T>::LinkedList()
{
	head = nullptr;

}

template<class T>
typename LinkedList<T>::Node * LinkedList<T>::addSorted(T v)
{
	typedef LinkedList<T>::Node Node;
	Node* put = new Node(v);

	Node* prev = nullptr;
	Node* curr = head;
	while (curr != nullptr) {
		if (!(curr->value < v)) break;
		prev = curr;
		curr = curr->next;
	}
	if (prev == nullptr) {
		put->next = head;
		head = put;
	}
	else {
		prev->next = put;
		put->next = curr;
	}
	return put;
}

template<class T>
typename LinkedList<T>::Node * LinkedList<T>::get(T v)
{
	typedef LinkedList<T>::Node Node;

	Node* curr = head;
	while (curr != nullptr) {
		if (!(curr->value < v)) break;
		curr = curr->next;
	}
	if (curr == nullptr || curr->value != v) {
		return nullptr;
	}
	else
		return curr;
}

template<class T>
LinkedList<T>::Node::Node(T v)
{
	value = v;
	next = nullptr;
}

template<class T>
std::ostream & operator<<(std::ostream & o, LinkedList<T>& c)
{
	typename LinkedList<T>::Node * cur = c.head;
	while (cur != nullptr) {
		o << cur->value << c.delimeter;
		cur = cur->next;
	}
	return o;
}
#endif  /* LINKED_LIST_H_ */