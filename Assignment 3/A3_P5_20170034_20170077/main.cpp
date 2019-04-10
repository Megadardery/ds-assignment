#include <bits/stdc++.h>
using namespace std;


bool isPal(const string& word)
{
    stack <char> stck;
    for (int i = 0 ; i<(int)word.size()/2 ; ++i)
    {
        stck.push(word[i]);
    }
    for (int i = (int)(word.size()+1)/2 ; i<(int)word.size();++i)
    {
        if (stck.top()!=word[i]) return 0;
        stck.pop();
    }
    return 1;
}
int main()
{
i:
    string word;
    getline(cin,word);
    cout << (isPal(word)?"Palindrome":"Not Palindrome") << "\n";
    goto i;
}
