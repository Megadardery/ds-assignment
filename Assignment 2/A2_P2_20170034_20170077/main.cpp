#include <iostream>
#include <cstring>
#include <map>


using namespace std;
int main()
{
    map <string,int> mp;
    string s;
    while (cout << "Enter word : " && cin >> s && s != "done")
    {
        ++mp[s];
    }
    for (auto& it : mp)
    {
        cout << it.first << "\t" << it.second << "\n";
        if (tolower(it.first[0]) == 'a') mp.erase(it.first);
    }
    cout << "\nWords that not start with letter a \n\n";
    for (auto& it : mp)
    {
        cout << it.first << "\t" << it.second << "\n";
    }
    return 0;
}


