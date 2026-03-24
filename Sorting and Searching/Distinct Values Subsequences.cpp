#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    unordered_map<ll, ll> mpp;

    for (ll i = 0; i < n; i++)
    {
        ll num;
        cin >> num;
        mpp[num]++;
    }

    ll total = 1;

    for (auto it : mpp)
    {
        total = (1LL * total * (it.second + 1)) % mod;
    }

    cout << total - 1 << endl;
    return 0;
}
