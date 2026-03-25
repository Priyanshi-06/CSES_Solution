#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

ll solve(ll mid, vector<ll> &temp, ll t)
{
    ll cnt = 0;
    for (ll i = 0; i < (ll)temp.size(); i++)
    {
        cnt += (mid / temp[i]);
        if (cnt >= t)
            return cnt;
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, t;
    cin >> n >> t;
    ll low = 0, high = 1e18;
    vector<ll> temp(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> temp[i];
        high = min(high, temp[i]);
    }

    high = high * t;
    sort(temp.begin(), temp.end());

    ll ans = -1;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        ll cnt = solve(mid, temp, t);
        if (cnt >= t)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}
