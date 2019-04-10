#include <bits/stdc++.h>
using namespace std;
char open[] = "([{<";
char close[] = ")]}>";

int Type(char x){
    const int sz = 4;
    for(int i = 0; i < sz; ++i){
        if (open[i] == x) return i+1;
        if (close[i] == x) return -i-1;
    }
    return 0;
}

bool brackets(const string& tmp)
{
    string word;
    for (int i = 0 ; i<(int)tmp.size(); ++i)
    {

        if (tmp[i] == '/' && tmp[i+1] == '*')
        {
            i+=2;
            if (i >= tmp.size()) return 0;
            while (tmp[i] != '*' || tmp[i+1] != '/')
            {
                ++i;
                if (i == tmp.size()) return 0;
            }
            i+=2;
        }
        word+=tmp[i];
    }
    //()
    stack<char> stck;
    for(int i = 0; i < (int)word.size(); ++i){
        int t = Type(word[i]);
        if (!t) return 0;
        if (t>0)
            stck.push(word[i]);
        else{
            if (stck.empty() || stck.top() != open[~t])
                return 0;
            stck.pop();
        }
    }
    return stck.empty();
}
int main()
{
i:
    string word;
    getline(cin,word);
    cout << (brackets(word)?"Valid":"Invalid") << "\n";
    goto i;
}
