#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

bool dfs(ll i,stack<ll>& st,vector<ll>& visited,vector<vector<ll>>& adj)
{
    visited[i]=1;
    for(auto it:adj[i])
    {
        if(visited[it]==0)
        {
            if(dfs(it,st,visited,adj))
            return 1;
        }
        else if(visited[it]==1)
        return 1;
    }

    visited[i]=2;
    st.push(i);
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m;cin>>n>>m;

    vector<vector<ll>>adj(n+1);

    for(ll i=0;i<m;i++)
    {
        ll a,b;cin>>a>>b;
        adj[a].push_back(b);
    }

    stack<ll>st;
    vector<ll>visited(n+1,0);
    for(ll i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            if(dfs(i,st,visited,adj))
            {
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    return 0;
}
