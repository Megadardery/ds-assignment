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

		friend std::ostream& operator<<(std::ostream &o, Node root) {
			//CHANGE WHAT GETS PRINTED IN THE TREE IF YOU WANT
			return o << root.priority;
		}
	};
private:
	Node* root;

	Node* rotateRight(Node*& Q);
	Node* rotateLeft(Node*& P);
	Node* insert(Node*& root, T k, V v);
	V find(Node* root, T k);
public:
	Treap();
	void insert(T k, V v);
	V find(T k);

	Node* getRoot() {
		return root;
	}
	template<class U, class X>
	friend std::ostream& operator<<(std::ostream &o, Treap<U, X> tree);
};

template<class T, class V>
Treap<T, V>::Node::Node(T k, V v)
{
	key = k;
	value = v;
	left = right = nullptr;
	priority = rand();
}

template<class T, class V>
typename Treap<T, V>::Node * Treap<T, V>::rotateRight(Treap<T, V>::Node *& Q)
{
	typename Treap<T, V>::Node * lchild = Q->left;
	Q->left = lchild->right;
	lchild->right = Q;
	Q = lchild;
	return Q;
}

template<class T, class V>
typename Treap<T, V>::Node * Treap<T, V>::rotateLeft(Treap<T, V>::Node *& P)
{
	typename Treap<T, V>::Node * rchild = P->right;
	P->right = rchild->left;
	rchild->left = P;
	P = rchild;
	return P;
}

template<class T, class V>
typename Treap<T, V>::Node* Treap<T, V>::insert(Treap<T, V>::Node *& root, T k, V v)
{
	if (root == nullptr) {
		root = new Node(k, v);
		return root;
	}
	if (k < root->key) {
		Node* ret = insert(root->left, k, v);
		if (root->left->priority > root->priority)
			rotateRight(root);
		return ret;
	}
	else if (k > root->key) {
		Node* ret = insert(root->right, k, v);
		if (root->right->priority > root->priority)
			rotateLeft(root);
		return ret;
	}
	else
		return root;
}

template<class T, class V>
V Treap<T, V>::find(Treap<T, V>::Node * root, T k)
{
	if (root == nullptr) return k;
	if (k < root->key)
		return find(root->left, k);
	else if (k > root->key)
		return find(root->right, k);
	else 
		return root->value;
}

template<class T, class V>
Treap<T, V>::Treap()
{
	root = nullptr;
}

template<class T, class V>
void Treap<T, V>::insert(T k, V v)
{
	insert(root, k, v);
}

template<class T, class V>
V Treap<T, V>::find(T k)
{
	return find(root, k);
}



template<class T, class V>
void _printTree(std::ostream & o, std::string prefix, typename Treap<T, V>::Node* x, bool right) {
	const char* ROOT_ = " #---- ";
	const char* SPACE = "        ";
	const char* CHILD = "|       ";
	const char* UPPER = " /----- ";
	const char* LOWER = " \\----- ";
	if (x) {
		_printTree<T, V>(o, prefix + (!right ? CHILD : SPACE), x->right, true);
		if (prefix == "")
			o << ROOT_ << *x << "\n";
		else
			o << prefix << (right ? UPPER : LOWER) << *x << "\n";
		_printTree<T, V>(o, prefix + (right ? CHILD : SPACE), x->left, false);
	}
}

template<class T, class V>
std::ostream & operator<<(std::ostream & o, Treap<T, V> tree)
{
	const char* ROOT_ = " #---- ";
	const char* SPACE = "        ";
	typename Treap<T, V>::Node* x = tree.getRoot();
	if (x) {
		_printTree<T, V>(o, SPACE, x->right, true);
		o << ROOT_ << *x << "\n";
		_printTree<T, V>(o, SPACE, x->left, false);
	}
	return o;
}


#endif /* TREAP_H_ */

