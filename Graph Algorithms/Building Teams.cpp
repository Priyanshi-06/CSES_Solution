#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

bool dfs(ll i, ll c, vector<ll> &color, vector<vector<ll>> &adj)
{
    color[i] = c;
    for (auto it : adj[i])
    {
        if (color[it] == -1)
        {
            if (!dfs(it, 1 - c, color, adj))
                return 0;
        }
        else
        {
            if (color[it] == c)
                return 0;
        }
    }
    return 1;
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
        adj[b].push_back(a);
    }

    vector<ll> color(n + 1, -1);
    for (ll i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            if (!dfs(i, 0, color, adj))
            {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }

    for (ll i = 1; i <= n; i++)
    {
        cout << color[i] + 1 << " ";
    }
    cout << endl;
    return 0;
}
