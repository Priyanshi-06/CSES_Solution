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

    vector<string> grid(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    queue<pair<ll, ll>> q;
    vector<vector<ll>> dist(n, vector<ll>(m, 1e18));
    vector<vector<pair<ll, ll>>> parent(n, vector<pair<ll, ll>>(m, {-1, -1}));
    vector<vector<char>> move(n, vector<char>(m));

    ll startx = -1, starty = -1, endx = -1, endy = -1;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
            {
                q.push({i, j});
                dist[i][j] = 0;
                startx = i;
                starty = j;
            }
            if (grid[i][j] == 'B')
            {
                endx = i;
                endy = j;
            }
        }
    }

    while (!q.empty())
    {
        ll i = q.front().first;
        ll j = q.front().second;
        q.pop();

        vector<ll> dr = {-1, 0, 1, 0};
        vector<ll> dc = {0, 1, 0, -1};
        vector<ll> dir = {'U', 'R', 'D', 'L'};

        for (ll k = 0; k < 4; k++)
        {
            ll nr = i + dr[k];
            ll nc = j + dc[k];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && 1 + dist[i][j] < dist[nr][nc] && grid[nr][nc] != '#')
            {
                dist[nr][nc] = 1 + dist[i][j];
                parent[nr][nc] = {i, j};
                move[nr][nc] = dir[k];
                q.push({nr, nc});
            }
        }
    }

    if (dist[endx][endy] == 1e18)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        cout << dist[endx][endy] << endl;
        string path="";
        ll x=endx,y=endy;
        while(x!=startx || y!=starty)
        {
            path+=move[x][y];
            auto p=parent[x][y];
            x=p.first;
            y=p.second;
        }
        for(ll i=(ll)path.length()-1;i>=0;i--)
        {
            cout<<path[i];
        }
        cout<<endl;
    }
    return 0;
}
