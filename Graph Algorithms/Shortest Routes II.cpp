#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, 1e18));
    for (ll i = 1; i <= m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b],c);
        dist[b][a] = min(dist[a][b],c);
    }

    for (ll i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
    }

    for (ll via = 1; via <= n; via++)
    {
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= n; j++)
            {
                if (dist[i][via] != 1e18 && dist[via][j] != 1e18 && dist[i][via] + dist[via][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][via] + dist[via][j];
                }
            }
        }
    }

    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        ll dis = dist[a][b];
        if (dis == 1e18)
            cout << "-1" << endl;
        else
            cout << dis << endl;
    }
    return 0;
}
