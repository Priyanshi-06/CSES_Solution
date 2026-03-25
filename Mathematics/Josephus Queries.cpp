#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(ll n, ll k)
{
    if (n == 1)
        return 1;
    if (k <= (n + 1) / 2)
    {
        if (2 * k > n)
            return (2 * k) % n;
        else
            return 2 * k;
    }
    ll temp = solve(n / 2, k - (n + 1) / 2);
    if (n % 2 == 1)
        return 2 * temp + 1;
    return 2 * temp -1;
}

int main()
{
    ll q;
    cin >> q;

    while (q--)
    {
        ll n, k;
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
    return 0;
}
