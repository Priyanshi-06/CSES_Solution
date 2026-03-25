#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

ll findPower(ll base, ll pow, ll m)
{
    ll ans = 1;
    base = base % m;
    while (pow > 0)
    {
        if (pow % 2 == 0)
        {
            base = (base * base) % m;
            pow = pow / 2;
        }
        else
        {
            ans = (ans * base) % m;
            pow--;
        }
    }
    return ans;
}

int main()
{
    ll q;
    cin >> q;

    while (q--)
    {
        ll base, pow, pow2;
        cin >> base >> pow >> pow2;

        ll pow1 = findPower(pow, pow2, mod - 1) % mod;
        cout << findPower(base, pow1, mod) << endl;
    }
    return 0;
}
