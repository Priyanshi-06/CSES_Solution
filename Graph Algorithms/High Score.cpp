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
 
    vector<vector<ll>> edges;
 
    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }
    
    vector<ll> dist(n + 1, LLONG_MIN);
    dist[1]=0;

    for (ll i = 1; i <= n-1; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            ll u = edges[j][0];
            ll v = edges[j][1];
            ll wt = edges[j][2];
            if (dist[u] != LLONG_MIN && wt + dist[u] > dist[v])
            {
                dist[v] = wt + dist[u];
            }
        }
    }
 
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            ll u = edges[j][0];
            ll v = edges[j][1];
            ll wt = edges[j][2];
            if (dist[u] != LLONG_MIN && wt + dist[u] > dist[v])
            {
                dist[v]=1e17;
            }
        }
    }

    if(dist[n]>=1e16)
    cout<<"-1"<<endl;
    else
    cout<<dist[n]<<endl;
    return 0;
}
