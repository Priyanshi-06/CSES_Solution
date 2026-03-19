#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vector<ll> temp(n + 1);

    for (ll i = 0; i < n; i++)
    {
        ll num;
        cin >> num;
        temp[num] = i;
    }

    ll ans = 1;

    for (ll i = 2; i <= n; i++)
    {
        if (temp[i] < temp[i - 1])
            ans++;
    }
    cout << ans << endl;
    return 0;
}
