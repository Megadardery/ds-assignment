#include "StudentName.h"

StudentName::StudentName(std :: string n)
{
    int c = 0 , i;
    for (int i = 0 ; i<siz ; ++i) name[i] = "";
    for (i = 0 ; n[i] == ' ' && i<(int)n.size(); ++i); // skips until first letter
    for (i ;i < (int)n.size() ; ++i)
    {
        if (n[i] == ' ' && name[c].size()) c++;
        else if (n[i] != ' ')name[c]+=n[i];
    }
    if (c<(siz-1))
    {
        for (int i = c ; i<siz ; ++i) name[i] = name[c];
    }
}

StudentName::~StudentName()
{

}
void StudentName:: print()
{
    for (int i = 0 ; i<siz ; ++i) std :: cout << i+1 <<") "<<name[i] << "\n";
}
bool StudentName:: replace(int i , int j)
{
    if (i<0 || j>=siz || i>=siz || j<0) return 0;
    if (i == j) return 1;
    std :: string tmp;
    tmp = name[i];
    name[i] = name[j];
    name[j] = tmp;
    return 1;
}
