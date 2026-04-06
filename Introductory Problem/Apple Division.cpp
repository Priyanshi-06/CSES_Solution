#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

int main()
{
    ll n, sum = 0;
    cin >> n;
    vector<ll> temp(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> temp[i];
        sum += temp[i];
    }

    ll total = (1 << n);
    vector<ll> dp(total, 0);

    for (ll mask = 0; mask < total; mask++)
    {
        for (ll i = 0; i < n; i++)
        {
            if (mask & (1 << i))
                dp[mask] += temp[i];
        }
    }

    ll min_diff = 1e16;
    for (ll i = 0; i < total; i++)
    {
        min_diff = min(min_diff, abs(sum - 2LL * dp[i]));
    }

    cout << min_diff << endl;
    return 0;
}
