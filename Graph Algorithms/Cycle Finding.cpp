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

    vector<vector<ll>> edge;

    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        edge.push_back({a, b, c});
    }

    vector<ll> dist(n + 1, 0);
    vector<ll> parent(n + 1, -1);

    for (ll i = 1; i <= n - 1; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            ll u = edge[j][0];
            ll v = edge[j][1];
            ll wt = edge[j][2];
            if (wt + dist[u] < dist[v])
            {
                dist[v] = wt + dist[u];
                parent[v] = u;
            }
        }
    }
    bool flag = 0;
    ll x = -1;
    for (ll j = 0; j < m; j++)
    {
        ll u = edge[j][0];
        ll v = edge[j][1];
        ll wt = edge[j][2];
        if (wt + dist[u] < dist[v])
        {
            flag = 1;
            x = v;
            parent[v] = u;
            break;
        }
    }

    if (flag == 0)
        cout << "NO" << endl;
    else
    {
        for (ll i = 1; i <= n; i++)
        {
            x = parent[x];
        }

        vector<ll> ans;

        ll v = x;

        ans.push_back(v);
        for (ll u = parent[v]; u != v; u = parent[u])
        {
            ans.push_back(u);
        }
        ans.push_back(v);
        cout << "YES" << endl;
        for (ll i = (ll)ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
