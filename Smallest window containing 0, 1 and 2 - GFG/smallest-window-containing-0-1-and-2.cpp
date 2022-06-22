// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
        unordered_map<char,int>mp;
        int i=0,j=0,ans=INT_MAX;
        while(j<S.length()){
            mp[S[j]]++;
            while(mp.size()==3){
                ans=min(ans,j-i+1);
                mp[S[i]]--;
                if(mp[S[i]]==0)
                mp.erase(S[i]);
                i++;
            }
            j++;
        }
        return ans==INT_MAX?-1:ans;
        
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}  // } Driver Code Ends