#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

vector<ll> solve(ll start, vector<vector<pair<ll, ll>>> &adj)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, start});
    ll n = adj.size();
    vector<ll> visited(n, LLONG_MAX);
    visited[start] = 0;

    while (!pq.empty())
    {
        ll dis = pq.top().first;
        ll node = pq.top().second;
        pq.pop();

        if (dis > visited[node])
            continue;

        for (auto it : adj[node])
        {
            if (it.second + dis < visited[it.first])
            {
                visited[it.first] = it.second + dis;
                pq.push({it.second + dis, it.first});
            }
        }
    }
    return visited;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> adj(n + 1);

    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
    }

    vector<ll> ans = solve(1, adj);

    for (ll i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
