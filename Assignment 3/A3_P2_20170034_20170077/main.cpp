#include <bits/stdc++.h>
using namespace std;
template <typename T>
void mergeInto(list<T>& lis1 , const list<T> lis2)
{
     auto it2 = lis2.begin();
    for (auto it1 = lis1.begin() ; it1 != lis1.end() ; it1++)
    {
        //
        auto nxt = ++it1;
        --it1;
        while (nxt!=lis1.end() && *nxt == *it1){
            lis1.erase(nxt);
            nxt = ++it1;
            --it1;
        }
        //
        while (*it2 < *it1)
        {
            it1--;
            if (*(it1++) != *it2)
                lis1.insert(it1,*it2);

            it2++;
            if (it2 == lis2.end()) break;
        }
        if (it2 == lis2.end()) break;
    }
    while (it2 != lis2.end())
    {
        if (lis1.back() != *it2)
            lis1.push_back(*(it2));
        it2++;
    }
}
int main()
{
i:
    int n1,n2, tmp;
    list<int> lis1, lis2;

    cout << "Enter number of elements in the first list : ";
    cin >> n1;
    cout << "Enter number of elements in the second list : ";
    cin >> n2;
    cout << "Entering " << n1 << " elements of the first list\n";
    for (int i = 0 ; i<n1 ; ++i)
    {
        cin >> tmp;
        lis1.push_back(tmp);
    }
    cout << "Entering " << n2 << " elements of the second list\n";
    for (int i = 0 ; i<n2 ; ++i)
    {
        cin >> tmp;
        lis2.push_back(tmp);
    }
    mergeInto(lis1,lis2);
    for (auto& it:lis1)
    {
        cout <<it << " ";
    }
    cout << endl;
    goto i;
    int n12 ;
    cin >> n12;
}
