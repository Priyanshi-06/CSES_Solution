#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

ll solve(ll i, ll j, string &s, string &target, vector<vector<ll>> &dp)
{
    if (i == -1 && j == -1)
        return 0;

    if (i == -1)
        return j + 1;

    if (j == -1)
        return i + 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    ll op = INT_MAX;
    if (s[i] != target[j])
    {
        ll rep = 1 + solve(i - 1, j - 1, s, target, dp);
        ll del = 1 + solve(i - 1, j, s, target, dp);
        ll add = 1 + solve(i, j - 1, s, target, dp);
        op = min(op, min({rep, del, add}));
    }
    else
    {
        op = min(op, solve(i - 1, j - 1, s, target, dp));
    }
    return dp[i][j] = op;
}

int main()
{
    string s, target;
    cin >> s >> target;

    ll n = s.length(), m = target.length();
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, -1));
    cout << solve(n - 1, m - 1, s, target, dp) << endl;
    return 0;
}
