//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
        // code here
        unordered_map<char,int>mp;
        for(char ch:S) mp[ch]++;
        int i=0,j=S.size()-1;
        bool rev=false;
        while(i<=j){
            if(rev){
                if(mp[S[j]]>1){
                    mp[S[j]]--;
                    S[j]='#';
                    rev=!rev;
                }
                j--;
            }
            else{
                if(mp[S[i]]>1){
                    mp[S[i]]--;
                    S[i]='#';
                    rev=!rev;
                }
                i++;
                
            }
        }
        string ans;
        for(char ch:S){
            if(ch!='#') ans+=ch;
        }
        if(rev) reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends