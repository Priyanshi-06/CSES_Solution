#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;
 
ll start_node=-1,end_node=-1;
 
bool dfs(ll node,vector<ll>& parent, vector<ll>& visited, vector<vector<ll>>& adj)
{
    visited[node] = 1;
 
    for(auto it : adj[node])
    {
        if(visited[it] == 0)
        {
            parent[it] = node;
            if(dfs(it,parent,visited,adj))
                return true;
        }
        else if(visited[it] == 1)
        {
            start_node = it;
            end_node = node;
            return true;
        }
    }
 
    visited[node] = 2;
    return false;
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
 
    vector<ll>visited(n+1,0),parent(n+1,-1);
 
    for(ll i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            if(dfs(i,parent,visited,adj))
            {
                break;
            }
        }
    }
 
    if(start_node==-1)
    cout<<"IMPOSSIBLE"<<endl;
    else
    {
        vector<ll>cycle;
        cycle.push_back(start_node);
        ll node=end_node;
        while(node!=start_node)
        {
            cycle.push_back(node);
            node=parent[node];
        }
        cycle.push_back(start_node);
        cout<<cycle.size()<<endl;
        for(ll i=(ll)cycle.size()-1;i>=0;i--)
        {
            cout<<cycle[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
