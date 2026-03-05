#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;
vector<ll> parent, _rank;

ll findParent(ll u)
{
    if (parent[u] == u)
        return parent[u];
    return parent[u] = findParent(parent[u]);
}

void union_by_rank(ll u, ll v)
{
    ll pu = findParent(u);
    ll pv = findParent(v);
    if (pu == pv)
        return;
    else if (_rank[pu] < _rank[pv])
    {
        parent[pu] = pv;
        _rank[pv] += _rank[pu];
    }
    else
    {
        parent[pv] = pu;
        _rank[pu] += _rank[pv];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    parent.resize(n);
    _rank.resize(n, 0);
    for (ll i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        union_by_rank(a - 1, b - 1);
    }

    ll cnt = 0;
    vector<pair<ll, ll>> ans;
    for (ll i = 0; i < n - 1; i++)
    {
        ll pu = findParent(i);
        ll pv = findParent(i + 1);
        if (pu != pv)
        {
            cnt++;
            ans.push_back({i, i + 1});
            union_by_rank(i, i + 1);
        }
    }

    cout << cnt << endl;
    for (ll i = 0; i < cnt; i++)
    {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    }
    return 0;
}
