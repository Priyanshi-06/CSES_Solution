#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

ll countSubMatrix(char ch, vector<string> &temp, vector<vector<ll>> &dp)
{
    ll n = temp.size();
    ll cnt = 0;
    for (ll i = 0; i < n; i++)
    {
        if (temp[0][i] == ch)
        {
            dp[0][i] = 1;
            cnt++;
        }
        else
        {
            dp[0][i] = 0;
        }
        if (temp[i][0] == ch)
        {
            dp[i][0] = 1;
            cnt++;
        }
        else
        {
            dp[i][0] = 0;
        }
    }

    for (ll i = 1; i < n; i++)
    {
        for (ll j = 1; j < n; j++)
        {
            if (temp[i][j] != ch)
                dp[i][j] = 0;
            else
            {
                ll min_ele = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                dp[i][j] = 1 + min_ele;
                cnt += dp[i][j];
            }
        }
    }
    if (temp[0][0] == ch)
        cnt--;

    return cnt;
}

int main()
{
    ll n, k;
    cin >> n >> k;

    char ch = 'A';
    vector<string> temp(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> temp[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    for (ll i = 0; i < k; i++)
    {
        cout << countSubMatrix(ch, temp, dp) << endl;
        ch++;
    }
    return 0;
}
