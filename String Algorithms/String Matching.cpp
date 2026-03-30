#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

void findLPS(string &target, vector<ll> &lps)
{
    lps[0] = 0;
    ll i = 1, m = target.length(), len = 0;
    while (i < m)
    {
        if (target[i] == target[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len > 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main()
{
    string s, target;
    cin >> s >> target;

    ll n = s.length(), m = target.length(), cnt = 0;

    vector<ll> lps(m, 0);
    findLPS(target, lps);

    ll i = 0, j = 0;
    while (i < n)
    {
        if (s[i] == target[j])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            cnt++;
            j = lps[j - 1];
        }
        else if (s[i] != target[j])
        {
            if (j != 0)
                j = lps[j - 1];
            else
            {
                i++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}
