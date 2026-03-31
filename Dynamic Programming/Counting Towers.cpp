#include <bits/stdc++.h> // Includes all standard C++ libraries so you don't have to include them one by one
using namespace std;

#define ll long long // Creates a handy shortcut 'll' for 'long long' to handle very large numbers easily
int mod = 1e9 + 7; // A large prime number used to keep the answers from getting too big and causing errors (overflow)

// Create two lists (vectors) to store our pre-calculated answers up to 1,000,000.
// They are initially filled with 0s.
vector<ll> dp0(1e6 + 1, 0), dp1(1e6 + 1, 0);

// This function calculates all the possible answers ahead of time
void preCompute()
{
    // Base cases: the starting values for our sequences when n is 1
    dp0[1] = 1;
    dp1[1] = 1;

    // Loop to build the answers for all numbers from 2 up to 1,000,000
    for (ll i = 2; i <= 1e6; i++)
    {
        // Calculate the current value using the previous answers (at i - 1)
        // We use % mod at the end of each step to keep the numbers within a safe size limit
        dp0[i] = (2LL * dp0[i - 1] + dp1[i - 1]) % mod;
        dp1[i] = (4LL * dp1[i - 1] + dp0[i - 1]) % mod;
    }
}

int main()
{
    ll t;
    cin >> t; // Read how many test cases the user wants to check

    // Call the pre-calculation function ONCE before running the test cases.
    // This makes the program incredibly fast because it only does the heavy lifting once!
    preCompute();

    // Loop through each test case
    while (t--)
    {
        ll n;
        cin >> n; // Read the target number 'n' for the current test case

        // The final answer is the sum of both calculated states at position 'n'.
        // We apply % mod one last time in case adding them together pushes them over the limit.
        cout << (dp0[n] + dp1[n]) % mod << endl;
    }
    
    return 0; // End of the program
}
