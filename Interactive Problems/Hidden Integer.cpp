#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll l = 1, r = 1000000000;

    while (l < r)
    {
        ll mid = l + (r - l) / 2;
        cout << "? " << mid << endl;

        string ans;
        cin >> ans;
        if (ans == "YES")
            l = mid + 1;
        else
            r = mid;
    }

    cout << "! " << l << endl;
    return 0;
}
