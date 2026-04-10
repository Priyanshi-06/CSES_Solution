#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

vector<ll> seg;

void build(ll i, ll l, ll r)
{
    if (l == r)
    {
        seg[i] = 1;
        return;
    }

    ll mid = l + (r - l) / 2;
    build(2 * i + 1, l, mid);
    build(2 * i + 2, mid + 1, r);
    seg[i] = seg[(2 * i) + 1] + seg[(2 * i) + 2];
}

void update(ll i, ll l, ll r, ll idx)
{
    if (l == r)
    {
        seg[i] = 0;
        return;
    }

    ll mid = l + (r - l) / 2;
    if (idx > mid)
        update(2 * i + 2, mid + 1, r, idx);
    else
        update(2 * i + 1, l, mid, idx);
    seg[i] = seg[(2 * i) + 1] + seg[(2 * i) + 2];
}

ll query(ll i, ll l, ll r, ll k)
{
    if (l == r)
        return l;

    ll mid = l + (r - l) / 2;
    ll left_cnt = seg[(2 * i) + 1];
    if (k <= left_cnt)
        return query(2 * i + 1, l, mid, k);
    else
        return query(2 * i + 2, mid + 1, r, k - left_cnt);
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

    seg.resize(4 * n);

    build(0, 0, n-1);

    for (ll i = 0; i < n; i++)
    {
        ll k;
        cin >> k;
        ll ans_idx = query(0, 0, n - 1, k);
        cout << temp[ans_idx] << " ";
        update(0, 0, n - 1, ans_idx);
    }

    cout << endl;
    return 0;
}
