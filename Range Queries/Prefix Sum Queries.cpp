#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

vector<pair<ll, ll>> seg;

void build(ll i, ll l, ll r, vector<ll> &temp)
{
    if (l == r)
    {
        seg[i].first = temp[l];
        seg[i].second = temp[l];
        return;
    }

    ll mid = l + (r - l) / 2;
    build(2 * i + 1, l, mid, temp);
    build(2 * i + 2, mid + 1, r, temp);

    seg[i].first = seg[(2 * i) + 1].first + seg[(2 * i) + 2].first;
    seg[i].second = max(seg[(2 * i) + 1].second, seg[(2 * i) + 1].first + seg[(2 * i) + 2].second);
}

void update(ll i, ll l, ll r, ll idx, ll val)
{
    if (l == r)
    {
        seg[i].first = val;
        seg[i].second = val;
        return;
    }

    ll mid = l + (r - l) / 2;
    if (idx > mid)
        update((2 * i) + 2, mid + 1, r, idx, val);
    else
        update((2 * i) + 1, l, mid, idx, val);

    seg[i].first = seg[(2 * i) + 1].first + seg[(2 * i) + 2].first;
    seg[i].second = max(seg[(2 * i) + 1].second, seg[(2 * i) + 1].first + seg[(2 * i) + 2].second);
}

pair<ll, ll> query(ll i, ll l, ll r, ll start, ll end)
{
    if (end < l || r < start)
        return {0, -1e9};

    if (start <= l && r <= end)
        return seg[i];

    ll mid = l + (r - l) / 2;

    pair<ll, ll> left = query((2 * i) + 1, l, mid, start, end);
    pair<ll, ll> right = query((2 * i) + 2, mid + 1, r, start, end);

    pair<ll, ll> ans;
    ans.first = left.first + right.first;
    ans.second = max(left.second, left.first + right.second);
    return ans;
}

int main()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> temp(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> temp[i];
    }

    seg.resize(4 * n);

    build(0, 0, n - 1, temp);

    while (q--)
    {
        ll type;
        cin >> type;
        if (type == 1)
        {
            ll k, u;
            cin >> k >> u;
            update(0, 0, n - 1, k - 1, u);
        }
        else
        {
            ll a, b;
            cin >> a >> b;
            pair<ll, ll> p = query(0, 0, n - 1, a - 1, b - 1);
            cout << max(0LL, p.second) << endl;
        }
    }
    return 0;
}
