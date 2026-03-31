#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

ll solve(ll i, ll prev, ll &n, ll &m, vector<ll> &temp, vector<vector<ll>> &dp)
{
    if (i == n)
        return 1;

    if (dp[i][prev] != -1)
        return dp[i][prev];

    ll cnt = 0;
    if (temp[i] == 0)
    {
        ll start = (prev == 0) ? 1 : max(1LL, prev - 1);
        ll end = (prev == 0) ? m : min(m, prev + 1);

        for (ll j = start; j <= end; j++)
        {
            cnt = (cnt + solve(i + 1, j, n, m, temp, dp)) % mod;
        }
    }
    else
    {
        if (prev == 0 || abs(prev - temp[i]) <= 1)
        {
            cnt = solve(i + 1, temp[i], n, m, temp, dp) % mod;
        }
        else
            return 0;
    }

    return dp[i][prev] = cnt;
}

int main()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> temp(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> temp[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(m + 1, -1));
    cout << solve(0, 0, n, m, temp, dp) << endl;
    return 0;
}
