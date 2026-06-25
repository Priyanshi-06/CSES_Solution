#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

ll solve(ll n, vector<ll> &dp)
{
    if (n == 0)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    ll ans = 0;

    for (ll i = 1; i <= 6; i++)
    {
        if ((n - i) >= 0)
        {
            ans = (ans + solve(n - i, dp)) % mod;
        }
    }

    return dp[n] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vector<ll> dp(n + 1, -1);
    cout << solve(n, dp) << endl;
    return 0;
}
