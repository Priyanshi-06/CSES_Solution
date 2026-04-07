#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

ll dp[20][12][2][2];

ll solve(string s, ll pos, ll prev, ll tight, ll leading)
{
    if (pos == s.length())
        return 1;
    if (dp[pos][prev + 1][tight][leading] != -1)
        return dp[pos][prev + 1][tight][leading];

    ll limit = tight ? (s[pos] - '0') : 9;
    ll ans = 0;

    for (ll digit = 0; digit <= limit; digit++)
    {
        if (!leading && digit == prev)
            continue;

        ll new_leading = leading && (digit == 0);
        ll new_prev = new_leading ? -1 : digit;
        ll new_tight = tight && (digit == limit);
        ans += solve(s, pos + 1, new_prev, new_tight, new_leading);
    }

    return dp[pos][prev + 1][tight][leading] = ans;
}

int main()
{
    ll a, b;
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    ll ans1 = solve(to_string(a - 1), 0, -1, 1, 1);
    memset(dp, -1, sizeof(dp));
    ll ans2 = solve(to_string(b), 0, -1, 1, 1);
    cout << ans2 - ans1 << endl;
}
