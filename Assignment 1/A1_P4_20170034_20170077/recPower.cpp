#include <iostream>
#include <cstring>
#include <algorithm>

typedef long double ld;
ld power1 (int n, int exp);
ld power2 (int n, int exp);
ld recpower1 (int n, int exp);
ld recpower2 (int n, int exp, int* mem);
using namespace std;

int main()
{
    i:
    int n , d;
    cin >> n >> d;
    cout << power1 (n,d) << "   " << power2(n,d) << endl;
    goto i;
    return 0;
}

ld power1 (int n, int exp)
{
    if (!n && !exp) return 1/0.0;
    if (exp < 0 ) return 1/recpower1(n,-exp);
    return recpower1(n, exp);
}

ld recpower1(int n, int exp)
{
    return (exp == 0? 1 : n*recpower1(n,exp-1));
}

ld power2 (int n, int exp)
{
    if (!n && !exp) return 1/0.0;
    int* mem = new int [abs(exp)+2];
    memset(mem,-1,sizeof mem[0] * (abs(exp)+2));
    mem[0] = 1;
    if (exp<0) return (1/recpower2(n,-exp,mem));
    return (recpower2(n,exp , mem));
}

ld recpower2(int n, int exp, int* mem)
{
    if (exp == 1) return (mem[exp] = n);
    if (mem[exp] != -1) return mem[exp];
    int& ret = mem[exp/2];
    ret = recpower2(n,exp/2, mem);
    if (exp&1) return n*(mem[exp-1]=(recpower2(n,exp-1 , mem)));
    return (ret*ret);
}
