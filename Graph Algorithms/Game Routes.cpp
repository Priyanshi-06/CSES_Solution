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
    vector<ll> indegree(n + 1, 0);
    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }

    // method - 1 : using dfs
    //  vector<ll> dp(n + 1, -1);
    //  cout << dfs(1, n, adj, dp) << endl;

    // method - 2 : using toposort
    vector<ll> dp(n + 1, 0);
    dp[1] = 1;

    queue<ll> q;
    for (ll i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        ll node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            dp[it] = (dp[it] + dp[node]) % mod;
            if (indegree[it] > 0)
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
    }

    cout << dp[n] << endl;
    return 0;
}
