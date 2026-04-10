#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

int main()
{
    string s;
    cin >> s;

    ll n = s.length();

    string newStr = "#";

    for (ll i = 0; i < n; i++)
    {
        newStr += s[i];
        newStr += "#";
    }

    ll m = newStr.length();

    vector<ll> p(m, 0);

    ll center = 0, right = 0;
    ll max_len = 0, max_center = 0;

    for (ll i = 0; i < m; i++)
    {
        ll mirror_idx = (2 * center) - i;
        if (right > i)
        {
            p[i] = min(p[mirror_idx], right - i);
        }

        ll a = i + (p[i] + 1);
        ll b = i - (p[i] + 1);

        while (b >= 0 && a < m && newStr[a] == newStr[b])
        {
            b--;
            a++;
            p[i]++;
        }

        if (p[i] >= max_len)
        {
            max_center = i;
            max_len = p[i];
        }

        if (i + p[i] > right)
        {
            center = i;
            right = i + p[i];
        }
    }

    string ans = "";
    for (ll i = (max_center - max_len); i <= (max_center + max_len); i++)
    {
        if (newStr[i] == '#')
            continue;

        ans += newStr[i];
    }

    cout << ans << endl;
    return 0;
}
