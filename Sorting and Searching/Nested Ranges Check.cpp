#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

static bool compare(pair<pair<ll, ll>, ll> &a, pair<pair<ll, ll>, ll> &b)
{
    if (a.first.first == b.first.first)
        return a.first.second > b.first.second;
    return a.first.first < b.first.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vector<pair<pair<ll, ll>, ll>> temp;

    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        temp.push_back({{a, b}, i});
    }

    vector<ll> contain(n, 0), part(n, 0);

    sort(temp.begin(), temp.end(), compare);

    ll max_ele = 0;
    for (ll i = 0; i < n; i++)
    {
        if (temp[i].first.second <= max_ele)
        {
            part[temp[i].second] = 1;
        }
        max_ele = max(max_ele, temp[i].first.second);
    }

    ll min_ele = 2e9;

    for (ll i = n - 1; i >= 0; i--)
    {
        if (temp[i].first.second >= min_ele)
        {
            contain[temp[i].second] = 1;
        }
        min_ele = min(min_ele, temp[i].first.second);
    }

    for (ll i = 0; i < n; i++)
    {
        cout << contain[i] << " ";
    }
    cout << endl;

    for (ll i = 0; i < n; i++)
    {
        cout << part[i] << " ";
    }
    cout << endl;
    return 0;
}
