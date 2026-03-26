#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

void dfs_for_down(ll node, ll parent, vector<vector<ll>> &adj, vector<ll> &down)
{
    down[node] = 0;
    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        dfs_for_down(it, node, adj, down);
        down[node] = max(down[node], 1 + down[it]);
    }
}

void dfs_for_up(ll node, ll parent, vector<vector<ll>> &adj, vector<ll> &up, vector<ll> &down)
{
    ll max1_node = -1, max2_node = -1, best_node = -1;

    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        if (down[it] > max1_node)
        {
            max2_node = max1_node;
            max1_node = down[it];
            best_node = it;
        }
        else if (down[it] > max2_node)
        {
            max2_node = down[it];
        }
    }

    for (auto it : adj[node])
    {
        if (it == parent)
            continue;

        ll long_down_path = 0;
        if (it == best_node)
            long_down_path = max2_node + 1;
        else
            long_down_path = max1_node + 1;

        up[it] = 1 + max(up[node], long_down_path);
        dfs_for_up(it, node, adj, up, down);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vector<vector<ll>> adj(n + 1);

    for (ll i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<ll> up(n + 1, 0), down(n + 1, 0);

    dfs_for_down(1, -1, adj, down);
    up[1] = 0;
    dfs_for_up(1, -1, adj, up, down);

    for (ll i = 1; i <= n; i++)
    {
        cout << max(up[i], down[i]) << " ";
    }
    cout << endl;
    return 0;
}
