#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

int main()
{
    ll n, x;
    cin >> n >> x;

    vector<ll> w(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    ll total = 1 << n;
    vector<pair<ll, ll>> dp(total, {1e18, 1e18});

    dp[0] = {1, 0};

    for (ll mask = 0; mask < total; mask++)
    {
        ll ride = dp[mask].first;
        ll wt = dp[mask].second;
        if (ride == 1e18)
            continue;

        for (ll i = 0; i < n; i++)
        {
            if (mask & (1 << i))
                continue;

            ll newMask = mask | (1 << i);
            pair<ll, ll> temp;
            if (wt + w[i] <= x)
                temp = {ride, wt + w[i]};
            else
                temp = {ride + 1, w[i]};

            dp[newMask] = min(dp[newMask], temp);
        }
    }

    cout << dp[total - 1].first << endl;
    return 0;
}
