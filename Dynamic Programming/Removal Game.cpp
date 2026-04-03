#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

int main()
{
    ll n;
    cin >> n;

    vector<ll> temp(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> temp[i];
    }

    vector<ll> pre(n, 0);
    pre[0] = temp[0];

    for (ll i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + temp[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(n, 0));

    for (ll i = 0; i < n; i++)
    {
        dp[i][i] = temp[i];
    }

    for (ll len = 2; len <= n; len++)
    {
        for (ll start = 0; start <= n - len; start++)
        {
            ll end = start + len - 1;
            ll sum = pre[end];
            if (start > 0)
                sum -= pre[start - 1];
            ll first = sum - dp[start + 1][end];
            ll last = sum - dp[start][end - 1];
            dp[start][end] = max(first, last);
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}
