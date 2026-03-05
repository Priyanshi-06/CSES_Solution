#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

ll start_node = -1, end_node = -1;
bool dfs(ll node, ll p, vector<ll> &parent, vector<vector<ll>> &adj, vector<ll> &visited)
{
    visited[node] = 1;

    for (auto it : adj[node])
    {
        if (it == p)
            continue;

        if (!visited[it])
        {
            parent[it] = node;
            if (dfs(it, node, parent, adj, visited))
            {
                return 1;
            }
        }
        else
        {
            start_node = it;
            end_node = node;
            return 1;
        }
    }
    return 0;
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

    vector<ll> visited(n + 1, 0);
    vector<ll> parent(n + 1, -1);

    for (ll i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, -1, parent, adj, visited))
            {
                break;
            }
        }
    }

    if (start_node == -1)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<ll> path;
    path.push_back(start_node);

    ll node = end_node;
    while (node != start_node)
    {
        path.push_back(node);
        node = parent[node];
    }

    path.push_back(start_node);
    cout << path.size() << endl;

    for (auto a : path)
        cout << a << " ";
    cout << endl;
    return 0;
}
