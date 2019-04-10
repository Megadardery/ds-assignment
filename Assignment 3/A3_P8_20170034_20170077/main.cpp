#include <bits/stdc++.h>
using namespace std;
class Stack{
queue<int> data;
public :
    int top()
    {
        return data.front();
    }
    void pop()
    {
        data.pop();
    }
    void push(const int& i)
    {
        int sz = data.size();
        data.push(i);
        for(int i = 0; i < sz; ++i){
            data.push(data.front());
            data.pop();
        }
    }
};
int main()
{
    Stack t;
i:
    cout << "1-push\n2-pop\n3-top\nChoose: ";
    int c;
    cin >>  c;
    if (c == 1)
        cin >> c, t.push(c);
    else if (c == 2)
        t.pop();
    else if (c==3)
        cout << t.top() << endl;
    goto i;
}
