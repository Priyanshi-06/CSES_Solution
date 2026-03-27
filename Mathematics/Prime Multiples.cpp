#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll cnt = 0;

void solve(ll idx, ll mul, ll depth, ll k, vector<ll> &prime, ll n)
{
    for (ll i = idx; i < k; i++)
    {
        if (mul > (n / prime[i]))
            continue;
        ll new_mul = mul * prime[i];
        if (depth % 2 == 0)
            cnt += (n / new_mul);
        else
            cnt -= (n / new_mul);
        solve(i + 1, new_mul, depth + 1, k, prime, n);
    }
}

int main()
{

    ll n, k;
    cin >> n >> k;

    vector<ll> prime(k);
    for (int i = 0; i < k; i++)
    {
        cin >> prime[i];
    }

    solve(0, 1, 0, k, prime, n);
    cout<<cnt<<endl;
    return 0;
}
