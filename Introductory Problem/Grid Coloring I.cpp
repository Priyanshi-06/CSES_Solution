#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    vector<string> temp(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> temp[i];
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            ll cnta = 0, cntb = 0, cntc = 0, cntd = 0;
            if (i - 1 >= 0)
            {
                if (temp[i - 1][j] == 'A')
                    cnta++;
                else if (temp[i - 1][j] == 'B')
                    cntb++;
                else if (temp[i - 1][j] == 'C')
                    cntc++;
                else
                    cntd++;
            }

            if (j - 1 >= 0)
            {
                if (temp[i][j - 1] == 'A')
                    cnta++;
                else if (temp[i][j - 1] == 'B')
                    cntb++;
                else if (temp[i][j - 1] == 'C')
                    cntc++;
                else
                    cntd++;
            }

            if (cnta == 0 && temp[i][j] != 'A')
                temp[i][j] = 'A';
            else if (cntb == 0 && temp[i][j] != 'B')
                temp[i][j] = 'B';
            else if (cntc == 0 && temp[i][j] != 'C')
                temp[i][j] = 'C';
            else if (cntd == 0 && temp[i][j] != 'D')
                temp[i][j] = 'D';
        }
    }

    for (ll i = 0; i < n; i++)
    {
        for(ll j=0;j<m;j++)
        {
            cout<<temp[i][j];
        }
        cout<<endl;
    }
    return 0;
}
