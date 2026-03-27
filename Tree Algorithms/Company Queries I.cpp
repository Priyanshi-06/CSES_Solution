#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, q;
    cin >> n >> q;
    vector<ll> temp(n + 1);
    for (ll i = 2; i <= n; i++)
    {
        cin >> temp[i];
    }

    ll max_step = log2(n) + 1;
    vector<vector<ll>> ans(max_step, vector<ll>(n + 1, -1));

    for (ll j = 2; j <= n; j++)
    {
        ans[0][j] = temp[j];
    }

    for (ll i = 1; i < max_step; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            if (ans[i - 1][j] != -1)
                ans[i][j] = ans[i - 1][ans[i - 1][j]];
            else
                ans[i][j] = -1;
        }
    }

    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        bool flag = 0;
        for (ll i = 0; i < max_step; i++)
        {
            if (b & (1LL << i))
            {
                a = ans[i][a];
                if (a == -1)
                {
                    cout << "-1" << endl;
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0)
            cout << a << endl;
    }
    return 0;
}
