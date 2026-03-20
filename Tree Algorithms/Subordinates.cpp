#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dfs(ll i, vector<vector<ll>> &adj, vector<ll> &ans)
{
    ll cnt = 0;
    for (auto it : adj[i])
    {
        cnt += dfs(it, adj, ans);
    }
    return ans[i] = 1 + cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vector<vector<ll>> adj(n + 1);

    for (ll i = 2; i <= n; i++)
    {
        ll num;
        cin >> num;
        adj[num].push_back(i);
    }

    vector<ll> ans(n + 1);

    dfs(1, adj, ans);

    for (ll i = 1; i <= n; i++)
    {
        cout << ans[i] - 1 << " ";
    }

    cout << endl;
    return 0;
}
