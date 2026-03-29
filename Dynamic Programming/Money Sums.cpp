#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(ll i, vector<ll> &temp, set<ll> &st, ll sum, vector<vector<ll>> &dp)
{
    ll n = temp.size();
    if (i == n)
    {
        if (sum != 0)
        {
            st.insert(sum);
        }
        return;
    }

    if (dp[i][sum] != -1)
        return;

    dp[i][sum] = 1;
    solve(i + 1, temp, st, sum, dp);
    solve(i + 1, temp, st, sum + temp[i], dp);
}

int main()
{
    ll n;
    cin >> n;

    vector<ll> temp(n);

    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> temp[i];
        sum += temp[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(sum + 1, -1));
    set<ll> st;

    solve(0, temp, st, 0, dp);

    cout << st.size() << endl;
    for (auto it : st)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
