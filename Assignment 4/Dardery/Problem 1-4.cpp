#include <iostream>
#include <string>
#include <vector>
#include "BSTFCI.h"
using namespace std;

int main() {
	BSTFCI<int> tree1;
	tree1.insert(5);
	tree1.insert(3);
	tree1.insert(7);
	tree1.insert(2);
	tree1.insert(4);
	tree1.insert(9);
	tree1.insert(1);
	tree1.insert(8);
	tree1.insert(10);

	BSTFCI<int> tree2;
	tree2.insert(9);
	tree2.insert(8);
	tree2.insert(10);

	BSTFCI<int> tree3;
	tree3.insert(2);
	tree3.insert(3);
	tree3.insert(4);
	tree3.insert(1);

	cout << "a: "; tree1.printTree();
	cout << "b: "; tree2.printTree();
	cout << "c: "; tree3.printTree();

	cout << "a range (5 : 9) : "; tree1.printRange(5, 9); cout << endl;

	cout << "a is balanced: " << tree1.isBalanced() ? "yes" : "no"; cout << endl;
	cout << "b is balanced: " << tree2.isBalanced() ? "yes" : "no"; cout << endl;
	cout << "c is balanced: " << tree3.isBalanced() ? "yes" : "no"; cout << endl;
	cout << "b is subtree of a: " << tree2.isSubTreeOf(tree1) ? "yes" : "no"; cout << endl;
	cout << "c is subtree of a: " << tree3.isSubTreeOf(tree1) ? "yes" : "no"; cout << endl;
	cout << "a reversed: "; tree1.reverse(); tree1.printTree();
}