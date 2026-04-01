#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

vector<ll> seg;

void update(ll i, ll start, ll end, ll idx, ll val)
{
    if (start == end)
    {
        seg[i] = (seg[i] + val) % mod;
        return;
    }
    ll mid = (start + end) / 2;
    if (start <= idx && idx <= mid)
        update(2 * i, start, mid, idx, val);
    else
        update(2 * i + 1, mid + 1, end, idx, val);
    seg[i] = (seg[(2 * i)] + seg[(2 * i) + 1]) % mod;
}

ll query(ll i, ll start, ll end, ll l, ll r)
{
    if (r < start || end < l)
        return 0;
    if (l <= start && end <= r)
        return seg[i];

    ll mid = (start + end) / 2;
    ll left = query(2 * i, start, mid, l, r);
    ll right = query(2 * i + 1, mid + 1, end, l, r);
    return (left + right) % mod;
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> temp(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> temp[i];
    }

    vector<ll> sorted = temp;

    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    ll m = sorted.size();
    seg.resize(4 * m + 1, 0);

    ll total = 0;

    for (ll i = 0; i < n; i++)
    {
        ll idx = lower_bound(sorted.begin(), sorted.end(), temp[i]) - sorted.begin() + 1;

        ll cnt = 1;
        if (idx > 1)
        {
            cnt = (cnt + query(1, 1, m, 1, idx - 1)) % mod;
        }

        update(1, 1, m, idx, cnt);
        total = (total + cnt) % mod;
    }

    cout << total << endl;
    return 0;
}
