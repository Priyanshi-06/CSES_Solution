#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> adj(n + 1);
    vector<ll> indegree(n + 1);
    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }

    queue<ll> q;
    for (ll i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<ll> parent(n + 1, -1);
    vector<ll> topoSort;
    while (!q.empty())
    {
        ll node = q.front();
        q.pop();
        topoSort.push_back(node);
        for (auto it : adj[node])
        {
            if (indegree[it] > 0)
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
    }

    vector<ll> dist(n + 1, -1);
    dist[1] = 1;
    for (ll i = 0; i < (ll)topoSort.size(); i++)
    {
        if (dist[topoSort[i]] != -1)
        {
            for (auto it : adj[topoSort[i]])
            {
                if (dist[topoSort[i]] + 1 > dist[it])
                {
                    parent[it] = topoSort[i];
                    dist[it] = 1 + dist[topoSort[i]];
                }
            }
        }
    }

    if (dist[n] == -1)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        cout << dist[n] << endl;
        vector<ll> cycle;
        ll node = n;
        while (node != -1)
        {
            cycle.push_back(node);
            node = parent[node];
        }
        reverse(cycle.begin(), cycle.end());
        for (auto x : cycle)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
