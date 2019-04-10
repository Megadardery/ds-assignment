#include <bits/stdc++.h>
#include "Queue.h"
using namespace std;

int main()
{
  Queue <int> q;
    q.push(1);
    cout << q.front() << " ";
    q.pop();
    q.push(2);
    cout << q.front() << " ";
    q.pop();
    q.push(3);
    cout << q.front() << " ";
    q.pop();
    q.push(5);
    cout << q.front() << " ";
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.pop();
    q.pop();
    q.pop();
    cout << q.front() << " ";

    int n;cin>>n;



    return 0;
}
