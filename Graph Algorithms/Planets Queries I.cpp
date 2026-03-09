#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, q;
    cin >> n >> q;

    vector<vector<ll>> dp(30, vector<ll>(n + 1));

    for (ll i = 1; i <= n; i++)
    {
        cin >> dp[0][i]; 
    }

    for (ll j = 1; j < 30; j++)
    {
        for (ll i = 1; i <= n; i++)
        {
            dp[j][i] = dp[j - 1][dp[j - 1][i]];
        }
    }

    while (q--)
    {
        ll x, k;
        cin >> x >> k;

        for (ll i = 0; i < 30; i++)
        {
            if (k & (1 << i))
            {
                x = dp[i][x];
            }
        }
        
        cout << x <<endl; 
    }
    
    return 0;
}
