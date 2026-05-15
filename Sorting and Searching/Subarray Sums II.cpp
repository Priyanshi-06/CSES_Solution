#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, x;
    cin >> n >> x;

    vector<ll> temp(n);

    map<ll, ll> mpp;

    ll cnt = 0, sum = 0;
    mpp[0] = 1;
    for (ll i = 0; i < n; i++)
    {
        cin >> temp[i];
        sum += temp[i];
        ll target = sum-x;
        if (mpp.find(target) != mpp.end())
        {
            cnt += mpp[target];
        }

        mpp[sum]++;
    }

    cout << cnt << endl;
    return 0;
}
