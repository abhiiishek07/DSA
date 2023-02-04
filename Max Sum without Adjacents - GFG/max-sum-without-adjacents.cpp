//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int solve(int idx,int *arr,vector<int>&dp){
	    if(idx<0) return 0;
	    if(idx==0) return arr[0];
	    if(dp[idx]!=-1) return dp[idx];
	    int take=0,not_take=0;
	    take=arr[idx]+solve(idx-2,arr,dp);
	    not_take=solve(idx-1,arr,dp);
	    return dp[idx]=max(take,not_take);
	}
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int>dp(n,-1);
	    return solve(n-1,arr,dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends