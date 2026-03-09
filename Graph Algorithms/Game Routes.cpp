#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

ll dfs(ll i, ll n, vector<vector<ll>> &adj, vector<ll> &dp)
{
    if (i == n)
        return 1;

    if (dp[i] != -1)
        return dp[i];

    ll cnt = 0;
    for (auto it : adj[i])
    {
        cnt = (cnt + dfs(it, n, adj, dp)) % mod;
    }
    return dp[i] = cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    vector<ll> dp(n + 1, -1);
    cout << dfs(1, n, adj, dp) << endl;
    return 0;
}
