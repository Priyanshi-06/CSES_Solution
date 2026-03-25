#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

ll findPower(ll base, ll pow)
{
    ll ans = 1;
    while (pow > 0)
    {
        if (pow % 2 == 0)
        {
            base = (base * base) % mod;
            pow = pow / 2;
        }
        else
        {
            ans = (ans * base) % mod;
            pow--;
        }
    }
    return ans % mod;
}

int main()
{
    ll q;
    cin >> q;

    while (q--)
    {
        ll base, pow;
        cin >> base >> pow;

        cout << findPower(base, pow) << endl;
    }
    return 0;
}
