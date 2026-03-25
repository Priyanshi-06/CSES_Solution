#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

void countDivisor(vector<ll>& divisor)
{
    for (ll i = 1; i < 1000005; i++)
    {
        for (ll j = i; j < 1000005; j += i)
        {
            divisor[j]++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<ll> divisor(1000005, 0);
    countDivisor(divisor);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        cout << divisor[n] << endl;
    }
    return 0;
}
