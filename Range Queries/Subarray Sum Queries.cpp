#include<bits/stdc++.h>
using namespace std;

#define ll long long

struct Node
{
    ll sum = 0;
    ll pre = 0;
    ll suff = 0;
    ll ans = 0;
};

vector<Node> seg;

void build(ll i, ll l, ll r, vector<ll> &arr)
{
    if (l == r)
    {
        seg[i].sum = arr[l];
        seg[i].pre = max(0LL, arr[l]);
        seg[i].suff = max(0LL, arr[l]);
        seg[i].ans = max(0LL, arr[l]);
        return;
    }

    ll mid = (l + r) / 2;
    build((2 * i) + 1, l, mid, arr);
    build((2 * i) + 2, mid + 1, r, arr);
    Node L = seg[(2 * i) + 1];
    Node R = seg[(2 * i) + 2];
    seg[i].sum = (L.sum + R.sum);
    seg[i].pre = max(L.pre, (L.sum + R.pre));
    seg[i].suff = max((R.sum + L.suff), R.suff);
    seg[i].ans = max({L.ans, R.ans, L.suff + R.pre});
}

void update(ll i, ll l, ll r, ll idx, ll val)
{
    if (l == r)
    {
        seg[i].sum = val;
        seg[i].pre = max(0LL, val);
        seg[i].suff = max(0LL, val);
        seg[i].ans = max(0LL, val);
        return;
    }

    ll mid = (l + r) / 2;
    if (idx <= mid)
        update((2 * i) + 1, l, mid, idx, val);
    else
        update((2 * i) + 2, mid + 1, r, idx, val);

    Node L = seg[(2 * i) + 1];
    Node R = seg[(2 * i) + 2];
    seg[i].sum = (L.sum + R.sum);
    seg[i].pre = max(L.pre, (L.sum + R.pre));
    seg[i].suff = max((R.sum + L.suff), R.suff);
    seg[i].ans = max({L.ans, R.ans, L.suff + R.pre});
}

ll query(ll i, ll l, ll r, ll start, ll end)
{
    if (l > end || r < start)
        return INT_MIN;

    if (l >= start && r <= end)
        return max(seg[i].ans, seg[i].ans);

    ll mid = (l + r) / 2;
    ll left = query((2 * i) + 1, l, mid, start, end);
    ll right = query((2 * i) + 2, mid + 1, r, start, end);
    return max(left, right);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    vector<ll> arr(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    seg.resize(4 * n);
    build(0, 0, n - 1, arr);

    for (ll i = 0; i < m; i++)
    {
        ll idx, val;
        cin >> idx >> val;
        update(0, 0, n - 1, idx - 1, val);
        cout << query(0, 0, n - 1, 0, n - 1) << endl;
    }
    return 0;
}
