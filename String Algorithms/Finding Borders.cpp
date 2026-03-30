#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

void findLPS(string &s, vector<ll> &lps)
{
    ll n = s.length(), i = 1, len = 0;
    lps[0] = 0;
    while (i < n)
    {
        if (s[i] == s[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
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
    string s;
    cin >> s;

    ll n = s.length();
    vector<ll> lps(n, 0);

    findLPS(s, lps);
    ll len=lps[n-1];

    vector<ll>ans;
    while(len>0)
    {
        ans.push_back(len);
        len=lps[len-1];
    }

    for(ll i=(ll)ans.size()-1;i>=0;i--)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
