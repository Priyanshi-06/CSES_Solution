#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin >> n >> k;

    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
        cin >> arr[i];

    ll ans = 0;

    unordered_map<ll, ll> mpp;

    ll i = 0, j = 0;

    while (j < n)
    {
        mpp[arr[j]]++;

        while ((ll)mpp.size() > k)
        {
            mpp[arr[i]]--;
            if (mpp[arr[i]] == 0)
            {
                mpp.erase(arr[i]);
            }
            i++;
        }

        ans += (j - i + 1);
        j++;
    }
    cout << ans << endl;

    return 0;
}
