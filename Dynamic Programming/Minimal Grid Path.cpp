#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

int main()
{
    ll n;
    cin >> n;

    vector<string> temp(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> temp[i];
    }

    queue<pair<ll, ll>> q;
    q.push({0, 0});

    string ans = string(1, temp[0][0]);

    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    visited[0][0] = 1;

    while (!q.empty())
    {
        ll sz = q.size();
        char ch = 'z' + 1;
        vector<pair<ll, ll>> temp_cell;

        for (ll k = 0; k < sz; k++)
        {
            ll i = q.front().first;
            ll j = q.front().second;
            q.pop();

            temp_cell.push_back({i, j});

            if (i + 1 < n)
                ch = min(ch, temp[i + 1][j]);
            if (j + 1 < n)
                ch = min(ch, temp[i][j + 1]);
        }

        if (ch > 'z')
            break;

        ans += ch;
        for (ll k = 0; k < (ll)temp_cell.size(); k++)
        {
            ll i = temp_cell[k].first;
            ll j = temp_cell[k].second;
            if (i + 1 < n && ch == temp[i + 1][j] && !visited[i + 1][j])
            {
                visited[i+1][j]=1;
                q.push({i + 1, j});
            }
            if (j + 1 < n && ch == temp[i][j + 1] && !visited[i][j + 1])
            {
                visited[i][j+1]=1;
                q.push({i, j + 1});
            }
        }
    }

    cout << ans << endl;
    return 0;
}
