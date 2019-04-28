#include <iostream>
#include <set>
#include "BSTFCI.h"
using namespace std;
class word
{
    string data;
    set <int> line;
    string toLow(string s)
    {
        for (int i = 0 ; i<(int)s.size() ; ++i) s[i] = tolower(s[i]);
        return s;
    }
public:
    word()
    {

    }
    word(string d , int l)
    {
        data = d;
        line.insert(l);
    }
    void insert(int i)
    {
        line.insert(i);
    }
    void set_data (string& oth)
    {
        data = oth;
    }
    bool operator < (word& other)
    {
        return toLow(data) < toLow(other.data);
    }
    bool operator > (word& other)
    {
        return toLow(data) > toLow(other.data);
    }
    bool operator == (const word& other) const
    {
        return data == other.data;
    }
    void operator = (const word& other)
    {
        data = other.data;
        line = other.line;
    }
    friend ostream& operator << (ostream& out , const word& curr);
};
ostream& operator << (ostream& out , const word& curr)
{
    out <<curr.data << " : ";
    for (auto& it : curr.line)
        out << it << " ";
    return out;
}
void build (BSTFCI<word>& main , ostream& out = cout , istream& in = cin)
{
    int n;
    BSTNode<word>* currNode = nullptr;
    word srch("",0);
    string tmp , currWord;
    cout << "Enter number of lines : ";
    cin >> n;
    cin.ignore();
    for (int i = 1 ; i<=n ; ++i)
    {
        getline(in,tmp);
        tmp+=" ";
        for (int j = 0 ; j<(int)tmp.size();++j)
        {
            if (isalpha(tmp[j])) currWord+=tmp[j];
            else if (currWord.size())
            {
                srch.set_data(currWord);
                currNode = main.FindNode(srch);
                if (currNode) currNode->data.insert(i);
                else
                {
                    main.insert(word(currWord,i));
                }
                currNode = nullptr;
                currWord = "";
            }

        }
    }
}
int main()

{   BSTFCI<int> tree1;
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

	cout << "a: "; tree1.print(); cout << endl;
	tree1.printTree();
	cout << "b: "; tree2.print();cout << endl;
	tree2.printTree();
	cout << "c: "; tree3.print();cout << endl;
    tree3.printTree();

	cout << "a range (5 : 9) : "; tree1.printRange(5, 9); cout << endl;

	cout << "a is balanced: " << (tree1.isBalanced() ? "yes" : "no"); cout << endl;
	cout << "b is balanced: " << (tree2.isBalanced() ? "yes" : "no"); cout << endl;
	cout << "c is balanced: " << (tree3.isBalanced() ? "yes" : "no"); cout << endl;
	cout << "b is subtree of a: " << (isSubTree(tree2,tree1) ? "yes" : "no"); cout << endl;
	cout << "c is subtree of a: " << (isSubTree(tree3,tree1) ? "yes" : "no"); cout << endl;
	cout << "a reversed: ";       tree1.flip(); tree1.print(); tree1.printTree();
	cout << "a reversed Again: "; tree1.flip(); tree1.print(); tree1.printTree();

	cout << "\n\n-------------------------------------------------\nTask 5\n\n";

	BSTFCI<word> tree5;
	build(tree5);
	cout << "\n\n";
	tree5.print('\n');
	tree5.printTree();

	cout << "\n\nProgram executed successfully\n";

	int n ; cin >> n;
    return 0;
}
/*
I am for truth,
no matter who tells it.
I am for justice,
no matter who it is for or against.
Malcolm X
*/
/*
The only thing that will make you happy
is being happy with who you are,
not who people think you are.
*/
/*
First best is falling in love.
Second best is being in love.
Least best is falling out of love.
But any of it is better than never having been in love.
*sadface*
*/
