#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct Node
{
    Node<T>* nxt;
    T data;
    int pr;
};
template <typename T>
class PriorityQueue
{
    Node<T>* head = nullptr;
public:
    ~PriorityQueue()
    {
        //a b c
        Node<T>* tmp = head;
        Node<T>* t;
        while (tmp->nxt)
        {
            t = tmp;
            tmp = tmp->nxt;
            delete t;
        }
        delete tmp;
    }
    void enqueue(T val, int p)
    {
        ///p = -p; for reversing
        Node<T>* ins = new Node<T>();
        ins->data = val;
        ins->pr = p;
        if (head == nullptr)
        {
            head = ins;
            return;
        }

        Node<T>* curr = head;
        while (curr->nxt && curr->nxt->pr <= p)
        {
            curr = curr->nxt;
        }
        if (curr == head && head->pr > p)
        {
            ins->nxt = head;
            head = ins;
        }
        else
        {
            Node<T>* tmp = curr->nxt;
            curr->nxt = ins;
            ins->nxt = tmp;
        }
    }
    T dequeue()
    {

        assert (head);
        T ret = head->data;
        Node<T>* tmp = head;
        head = head->nxt;
        delete tmp;
        return ret;
    }

};
int main()
{
    PriorityQueue<string> pq;
    pq.enqueue("belal",10);
    pq.enqueue("drdr",10);
    pq.enqueue("b",9);
    pq.enqueue("pp",12);
    pq.enqueue("tt",10);
    pq.enqueue("toto",11);
    cout << pq.dequeue() << "\n";
    cout << pq.dequeue() << "\n";
    cout << pq.dequeue() << "\n";
    cout << pq.dequeue() << "\n";
    cout << pq.dequeue() << "\n";
    cout << pq.dequeue() << "\n";
    int n ;
    cin >> n;
    return 0;
}

