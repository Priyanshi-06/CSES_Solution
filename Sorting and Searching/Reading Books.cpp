#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    ll sum = 0, max_ele = INT_MIN;

    for (ll i = 0; i < n; i++)
    {
        ll num;
        cin >> num;
        sum += num;
        max_ele = max(max_ele, num);
    }

    cout << max(sum, 2 * max_ele) << endl;
    return 0;
}
