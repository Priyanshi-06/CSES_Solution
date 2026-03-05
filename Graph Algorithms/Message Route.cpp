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

    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<ll> q;
    vector<ll> dis(n + 1, INT_MAX);
    vector<ll> parent(n + 1, -1);
    dis[1] = 1;
    q.push(1);
    while (!q.empty())
    {
        ll node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (1 + dis[node] < dis[it])
            {
                dis[it] = 1 + dis[node];
                parent[it] = node;
                q.push(it);
            }
        }
    }
    if (dis[n] == INT_MAX)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        vector<ll> path;
        ll curr = n;
        while (curr != -1)
        {
            path.push_back(curr);
            curr = parent[curr];
        }

        cout << path.size() << endl;
        for (ll i = (ll)path.size() - 1; i >= 0; i--)
        {
            cout << path[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
