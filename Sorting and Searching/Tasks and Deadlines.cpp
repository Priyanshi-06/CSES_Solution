#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

static bool compare(pair<ll, ll> &a, pair<ll, ll> &b)
{
    if (a.first == b.first)
        return a.second >= b.second;
    return a.first < b.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vector<pair<ll, ll>> temp;

    for (ll i = 0; i < n; i++)
    {
        ll a, d;
        cin >> a >> d;
        temp.push_back({a, d});
    }

    sort(temp.begin(), temp.end(), compare);

    ll end = 0, reward = 0;

    for (ll i = 0; i < n; i++)
    {
        ll a = temp[i].first;
        ll d = temp[i].second;
        end += a;
        reward += (d - end);
    }

    cout << reward << endl;
    return 0;
}
