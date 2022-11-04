//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll solve(int n,vector<ll>&dp){
	    if(n<=2)
	    return n+1;
	    
	    if(dp[n]!=-1)
	    return dp[n];
	    
	    return dp[n]= (solve(n-1,dp)%1000000007+solve(n-2,dp)%1000000007)%1000000007;
	}
	ll countStrings(int n) {
	    // code here
	    vector<ll>dp(n+1,-1);
	    return solve(n,dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends