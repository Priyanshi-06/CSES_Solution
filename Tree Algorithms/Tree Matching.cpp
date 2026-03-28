#include <bits/stdc++.h>
using namespace std;
#define ll long long

// dfs function to calculate the maximum matching
// node: the current node we are standing on
// parent: where we came from (to avoid walking backwards)
// adj: the tree structure
// dp: our memory table to store the maximum pairs
void dfs(ll node, ll parent, vector<vector<ll>> &adj, vector<vector<ll>> &dp)
{
    // This will hold the sum of the absolute best scores from all my children
    ll total_child = 0; 
    
    // --- STEP 1: Visit all children first (Bottom-Up approach) ---
    for (auto it : adj[node])
    {
        // Don't go backwards to the parent!
        if (it == parent)
            continue;
            
        // Travel further down the tree to the child
        dfs(it, node, adj, dp);
        
        // Add the absolute best score this child could get 
        // (whether that child paired up or stayed single)
        total_child += max(dp[it][0], dp[it][1]);
    }

    // --- STEP 2: What if the current node stays SINGLE? ---
    // If I stay single, my score is just the sum of the best scores of my children.
    dp[node][0] = total_child;
    
    // Initialize the score for "pairing up" to 0 for now
    dp[node][1] = 0;

    // --- STEP 3: What if the current node PAIRS UP with one child? ---
    for (auto it : adj[node])
    {
        // Again, don't look at the parent
        if (it == parent)
            continue;
            
        // The Magic Formula! Let's test pairing up with THIS specific child (it).
        // 1. Start with the best score of ALL children: total_child
        // 2. Subtract this specific child's old best score: - max(dp[it][0], dp[it][1])
        // 3. Force this child to stay single (because its hands are now tied with ME): + dp[it][0]
        // 4. Add 1 because ME and THIS CHILD just made a brand new pair: + 1
        ll current_choice = total_child - max(dp[it][0], dp[it][1]) + dp[it][0] + 1;
        
        // Keep track of the highest score possible from trying all the different children
        dp[node][1] = max(dp[node][1], current_choice);
    }
}

int main()
{
    ll n;
    cin >> n;

    // Create the tree. We use n+1 because nodes are usually numbered 1 to n
    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        // Connect node 'a' to 'b', and 'b' to 'a' (an undirected tree)
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Create the DP table: size (n+1) rows, 2 columns. 
    // FIX: Initialize with 0 instead of -1. 
    // If a leaf node has no children, its default score should be 0, not -1.
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
    
    // Start the DFS from node 1. It has no parent, so we pass -1.
    dfs(1, -1, adj, dp);
    
    // The final answer is the best score of the root node (Node 1)
    // whether it decided to stay single (dp[1][0]) or pair up (dp[1][1])
    cout << max(dp[1][0], dp[1][1]) << endl;
    
    // FIX: Return 0 instead of 1 to avoid a "Runtime Error" on online judges.
    return 0; 
}
