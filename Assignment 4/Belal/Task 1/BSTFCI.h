#ifndef BSTFCI_H
#define BSTFCI_H
#include <iostream>
#include <string>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))


template<typename T>
struct BSTNode
{
    BSTNode<T>* right;
    BSTNode<T>* left;
    T data;
    int lvl;
};

template<typename T>
class BSTFCI
{
public:
    BSTNode<T>* root = nullptr;



    int util_insert(T data, BSTNode<T>*& curr)
    {
        int lvl = 0;
        if (!curr)
        {
            curr = new BSTNode<T>();
            curr->lvl = 1;
            curr->data = data;
            curr->left = curr->right = nullptr;
        }
        else if (data > curr->data)
        {
            lvl = util_insert(data,curr->right) + 1;
        }
        else if (data < curr->data)
        {
            lvl = util_insert(data,curr->left) + 1;
        }
        return curr->lvl = max(lvl,curr->lvl);
    }

    bool util_balance(BSTNode<T>* curr)
    {
        if (!curr) return 1;
        int RLvl = (curr->right ? curr->right->lvl : 0);
        int LLvl = (curr->left  ? curr->left ->lvl : 0);
        if (max(RLvl,LLvl) - min(RLvl,LLvl) > 1 || util_balance(curr->right) == 0 || util_balance(curr->left) == 0) return 0;
        return 1;
    }

    void util_flip(BSTNode<T>* curr)
    {
        if (curr->right) util_flip(curr->right);
        if (curr->left) util_flip(curr->left);

        BSTNode<T>* tmp = curr->right;
        curr->right = curr->left;
        curr->left = tmp;
    }
    void util_print (T& a, T& b, BSTNode<T>* curr, std :: ostream& out)
    {
        if (curr->left  && curr->data > a) util_print(a,b,curr->left,out);
        if ((curr->data >= a && curr->data <= b) || (!a && !b)) out << curr->data << " ";
        if (curr->right && curr->data < b) util_print(a,b,curr->right,out);
    }
    void util_printAll (BSTNode<T>* curr, std :: ostream& out , char delim)
    {
        if (curr->left) util_printAll(curr->left,out,delim);
        out << curr->data << delim;
        if (curr->right) util_printAll(curr->right,out,delim);
    }
    void util_printTree(std::string prefix, BSTNode<T>* curr, bool right,std::ostream& out)
     {
		if (curr) {
			util_printTree(prefix + (!right ? "|    " : "     "), curr->right, true,out);
			if (prefix == "")
				out << " #-- " << curr->data << " " << curr->lvl << "\n";
			else
				out << prefix << (right ? " /-- " : " \\-- ") << curr->data << " " << curr->lvl << "\n";
			util_printTree(prefix + (right ? "|    " : "     "), curr->left, false,out);
		}
    }
public:
    ~BSTFCI()
    {

    }
    BSTNode<T>* FindNode (T& req)
    {
        BSTNode<T>* curr = root;
        while (curr)
        {
            if (req > curr->data) curr = curr-> right;
            else if (req < curr->data) curr = curr ->left;
            else if (req == curr->data) break;
        }
        return curr;
    }
    void insert (T data)
    {
        util_insert(data,root);
    }
    bool isBalanced()
    {
        return util_balance(root);
    }
    void flip ()
    {
        util_flip(root);
    }
    void printRange (T a, T b, std :: ostream& out = std :: cout)
    {
        util_print(a,b,root,out);
        out << "\n";
    }
    void print (char delim = ' ',std :: ostream& out = std :: cout)
    {
        util_printAll(root,out,delim);
    }
    void printTree(std::ostream& out = std :: cout)
    {
		out << "\n________________________________________\n\n";
		if (root) {
			util_printTree("     ", root->right, true,out);
			out << " #-- " << root->data << " " <<root->lvl << "\n";
			util_printTree("     ", root->left, false,out);
		}
		out << "\n________________________________________\n\n";
    }
    template <typename F>
    friend bool isSubTree (BSTFCI<F>& first, BSTFCI<F>& second);

    template <typename F>
    friend bool same(BSTFCI<F>* t1, BSTFCI<F>* t2);


};
template <typename F>
bool same(BSTNode<F>* t1, BSTNode<F>* t2)
{
    if (!t1 || !t2) return t1 == t2;
    return (t1->data == t2->data? (same(t1->right,t2->right) && same(t1->left,t2->left)) : 0);
}
template <typename F>
bool isSubTree (BSTFCI<F>& first, BSTFCI<F>& second)
{
    BSTNode<F>* s = second.FindNode(first.root->data);
    BSTNode<F>* f = first.root;
    if (!s) return 1;
    return same(s,f);

}


#endif // BSTFCI_H
