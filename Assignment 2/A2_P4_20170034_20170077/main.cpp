#include <iostream>
#include <algorithm>
using namespace std;

int arr [100005];

bool check (int l, int w, int h)
{
    return ((l+w)>h && (l+h)>w && (w+h)>l);
}
int main()
{
    int n, sum = 0 , flag = 0;
    cout << "Enter the size of array : ";
    cin >> n;
    for (int i = 0 ; i < n ; ++i) cin >> arr[i];
    cout << "\n";
    if (n < 3)
    {
        cout << "No\n";
        return 0;
    }
    sort (arr,arr+n);
    for (int i = 3; i <= n && !flag ; ++i)
    {
        flag = check (arr[i-3],arr[i-1],arr[i-2]);
        if (flag) cout << arr[i-1] << " " << arr[i-2] << " " << arr[i-3] << "\n";
    }
    if (!flag) cout << "No\n";
    return 0;
}
