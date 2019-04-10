#include <bits/stdc++.h>
using namespace std;
template <typename P>
struct Node
{
    P data;
    Node<P>* nxt;
    Node<P>* prev;
};
template <typename T>
class List
{
    Node<T>* head;
    Node<T>* last;
    size_t siz;
public:
   /* class iterator
    {


    public :
        iterator operator ++ ()
        {

        }
        iterator operator ++ (int)
        {

        }
        iterator operator -- ()
        {

        }
        iterator operator -- (int)
        {

        }
        T& operator *()
        {

        }
        bool operator == (const iterator& it)
        {
            return *this == it;
        }
    };*/
    List()
    {
        siz = head = last = 0;
    }
    List(const T& val , int s)
    {
        assert(s>0);
        siz = s;
        head = new Node<T>();
        head->data = val;
        last = head;
        head->prev = 0;
        head->nxt = 0;
        s--;
        while (s--)
        {
            Node<T>* tmp = new Node<T>();
            last->nxt = tmp;
            tmp->data = val;
            tmp->prev = last;
            tmp->nxt = 0;
            last = tmp;
        }

    }
    ~List()
    {
        Node<T>* tmp;
        while (head->nxt)
        {
            tmp = head;
            head = head->nxt;
            delete tmp;
        }
        delete head;
        delete last;
    }
    size_t size()
    {
        return siz;
    }
    void push_back(const T& val)
    {
        ++siz;
        if (head == last && !head)
        {
            head = new Node<T>();
            head->data = val;
            head->nxt = head-> prev = 0;
            last = head;
        }
        else
        {
            Node<T>* tmp = new Node<T>();
            last->nxt = tmp;
            tmp->data = val;
            tmp->prev = last;
            tmp->nxt = 0;
            last = tmp;
        }

    }
    List<T>& operator = (const List<T>& cpy) // deep copy
    {
        if (cpy.head == nullptr) return nullptr;
        if (cpy.head == this->head) throw 0;
        Node<T>* tmp = cpy.head;
        while (tmp->nxt)
        {
            push_back(tmp->data);
            tmp = tmp->nxt;
        }
        push_back(tmp->data);
        delete cpy;
        return *this;
    }
    /*void insert (const T& val , iterator it)
    {

    }
    iterator erase (iterator it) // returns iterator of nxt and throw exception if erase last
    {
        --siz;
    }
    iterator begin()
    {

    }
    iterator end() // returns after last iterator
    {

    }
    */


};
int main()
{
    /*List<int> ll(5,2);
    ll.push_back(6);
    cout << ll.size() << endl;
    ll.push_back(7);
    cout << ll.size()<< "\n";
    for (auto it : ll)
    {
        cout << *it << " ";
        if (*it == 6)
        {
            cout << "\n"<<*(ll.erase (it)) << "\n";
        }
    }
    cout << "\n";
    for (auto it : ll)
    {
        cout << *it << " ";
    }
    cout << "\n";
    auto it = ll.begin();
    cout << *it << " " << *(++it) << " " << *(it++) << "\n";
    it = ll.end();
    --it;
    cout << *it << "\n";
    --it;
    ll.insert (100,it);
    cout << *it << " " << *(++it) << "\n";*/
    int n1;cin>>n1;
    return 0;
}
