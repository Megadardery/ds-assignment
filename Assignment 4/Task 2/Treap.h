#ifndef TREAP_H_
#define TREAP_H_

#include <iostream>

template<class T, class V>
class Treap {
public:
	class Node {
	public:
		Node *left, *right;
		T key;
		V value;
		int priority;

		Node(T k, V v);
		friend std::ostream& operator<<(std::ostream &o, Treap<T, V>::Node root);
	};
private:
	Node* root;

	Node* rotateRight(Node* Q);
	Node* rotateLeft(Node* P);
	Node* balance(Node* root);
	Node* insert(Node* root, T k, V v);
	V find(Node* root, T k);
public:
	Treap();
	void insert(T k, V v);
	V find(T k);

	template<class U, class X>
	friend std::ostream& operator<<(std::ostream &o, Treap<U, X> tree);
};

template<class T, class V>
Treap<T, V>::Node::Node(T k, V v)
{
}

template<class T, class V>
std::ostream & operator<<(std::ostream & o, typename Treap<T, V>::Node root)
{
	// TODO: insert return statement here
}

template<class T, class V>
std::ostream & operator<<(std::ostream & o, Treap<T, V> tree)
{
	// TODO: insert return statement here
}

template<class T, class V>
typename Treap<T, V>::Node * Treap<T, V>::rotateRight(Treap<T, V>::Node * Q)
{
	// TODO: insert return statement here
}

template<class T, class V>
typename Treap<T, V>::Node  * Treap<T, V>::rotateLeft(Treap<T, V>::Node * P)
{
	// TODO: insert return statement here
}

template<class T, class V>
typename Treap<T, V>::Node  * Treap<T, V>::balance(Treap<T, V>::Node * root)
{
	// TODO: insert return statement here
}

template<class T, class V>
typename Treap<T, V>::Node  * Treap<T, V>::insert(Treap<T, V>::Node * root, T k, V v)
{
	// TODO: insert return statement here
}

template<class T, class V>
V Treap<T, V>::find(Treap<T, V>::Node * root, T k)
{
	// TODO: insert return statement here
}

template<class T, class V>
Treap<T, V>::Treap()
{
	// TODO: insert return statement here
}

template<class T, class V>
void Treap<T, V>::insert(T k, V v)
{
	// TODO: insert return statement here
}

template<class T, class V>
V Treap<T, V>::find(T k)
{
	// TODO: insert return statement here
}

#endif /* TREAP_H_ */
