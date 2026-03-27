#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

ll dia = 0;
ll findDiameter(ll node, ll parent, vector<vector<ll>> &adj)
{
    ll longest = 0, second = 0;

    for (auto it : adj[node])
    {
        if (it == parent)
            continue;

        ll depth = 1 + findDiameter(it, node, adj);
        if (depth >= longest)
        {
            second = longest;
            longest = depth;
        }
        else if (depth > second)
        {
            second = depth;
        }
    }
    dia = max(dia, longest + second);
    return longest;
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

    findDiameter(1, -1, adj);
    cout << dia << endl;
    return 0;
}
