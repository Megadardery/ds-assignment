#ifndef _BSTFCI_H
#define _BSTFCI_H

#include <iostream>
#include <string>
template<typename T>
class BSTFCI {
	struct BSTNode {
		BSTNode* right = nullptr;
		BSTNode* left = nullptr;
		T val;
		int level;
	};
	BSTNode* root = nullptr;

	static bool _isBalanced(BSTNode* x) {
		if (x == nullptr)
			return 1;
		int r_level = 0, l_level = 0;
		if (x->right) {
			r_level = x->right->level;
			if (!_isBalanced(x->right)) return 0;
		}
		if (x->left) {
			l_level = x->left->level;
			if (!_isBalanced(x->left)) return 0;
		}
		return abs(r_level - l_level) <= 1;
	}
	static int insert(const T& val, BSTNode*& x) {
		if (x == nullptr) {
			x = new BSTNode;
			x->val = val;
			x->level = 1;	//leaf nodes' height is 1
		}
		else if (val > x->val) {
			int lvl = insert(val, x->right) + 1;
			if (x->level < lvl) x->level = lvl;
		}
		else if (val < x->val) {
			int lvl = insert(val, x->left) + 1;
			if (x->level < lvl) x->level = lvl;
		}
		else if (val == x->val) {
			x->val = val;
		}
		return x->level;
	}
	static void printRange(const T& low, const T& high, BSTNode* x) {
		if (x->left && x->val > low) {
			printRange(low, high, x->left);
		}
		if (x->val >= low && x->val <= high) {
			std::cout << x->val << " ";
		}
		if (x->right && x->val < high) {
			printRange(low, high, x->right);
		}
	}
	static void _reverse(BSTNode* x) {
		BSTNode* tmp = x->right;
		x->right = x->left;
		x->left = tmp;

		if (x->right) _reverse(x->right);
		if (x->left) _reverse(x->left);
	}
	static void _printTree(std::string prefix, BSTNode* x, bool right) {
		if (x) {
			_printTree(prefix + (!right ? "|    " : "     "), x->right, true);
			if (prefix == "")
				std::cout << " #-- " << x->val << "\n";
			else
				std::cout << prefix << (right ? " /-- " : " \\-- ") << x->val << "\n";
			_printTree(prefix + (right ? "|    " : "     "), x->left, false);
		}
	}
	static void _LPR(BSTNode* x) {
		if (x->left) _LPR(x->left);
		std::cout << x->val;
		if (x->right) _LPR(x->right);
	}
public:
	bool isBalanced() {
		return _isBalanced(root);
	}
	void insert(const T& val) {
		insert(val, root);
	}
	bool isSubTreeOf(const BSTFCI& big) {
		BSTNode* n = big.root;
		BSTNode* m = root;

		//we want to see if m is a subtree of n
		
		if (!m) return 1;		//null is subtree of null
		else if (!n) return 0;	//however not null is never a subtree of null

		const T& myval = m->val;

		while (n && myval != n->val) {
			if (myval > n->val)
				n = n->right;
			else if (myval < n->val)
				n = n->left;
		}
		return equivalent(n, m);
	}
	void printRange(const T& low, const T& high) {
		if (root) printRange(low, high, root);
	}
	void LPR() {
		if (root) _LPR(root);
	}
	void printTree() {
		std::cout << "\n________________________________________\n\n";
		if (root) {
			_printTree("     ", root->right, true);
			std::cout << " #-- " << root->val << "\n";
			_printTree("     ", root->left, false);
		}
		std::cout << "\n________________________________________\n\n";
	}
	void reverse() {
		if (root) _reverse(root);
	}
	static bool equivalent(BSTNode* a, BSTNode* b) {
		if (!a && !b)	//if both are null
			return 1;
		else if (!a || !b) //if only one of them is null
			return 0;

		if (a->val != b->val)
			return 0;
		else
			return equivalent(a->right, b->right) && equivalent(a->left, b->left);
	}
};
#endif