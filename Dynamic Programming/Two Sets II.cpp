#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

ll noOfWays(ll i, ll target, ll sum, ll n, vector<vector<ll>> &dp)
{
    if (i == n)
    {
        return target == (sum + i);
    }

    if (sum > target)
        return 0;

    if (dp[i][sum] != -1)
        return dp[i][sum];

    ll nottake = noOfWays(i + 1, target, sum, n, dp);
    ll take = noOfWays(i + 1, target, sum + i, n, dp);
    return dp[i][sum] = (take + nottake) % mod;
}

int main()
{
    ll n;
    cin >> n;

    ll total_sum = ((n) * (n + 1)) / 2;
    if (total_sum % 2 == 1)
        cout << 0 << endl;
    else
    {
        ll target = total_sum / 2;
        vector<vector<ll>> dp(n + 1, vector<ll>(target + 1, -1));
        cout << noOfWays(1, target, 0, n, dp) << endl;
    }
    return 0;
}
