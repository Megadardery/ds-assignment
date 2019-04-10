#include <bits/stdc++.h>
#include "Stack.h"
using namespace std;

int main()
{
    Stack<int> stck;
    stck.push(1);
    cout << stck.top() << " ";
    stck.pop();
    stck.push(2);
    cout << stck.top() << " ";
    stck.pop();
    stck.push(3);
    cout << stck.top() << " ";
    stck.pop();
    stck.push(5);
    cout << stck.top() << " ";
    return 0;
}
