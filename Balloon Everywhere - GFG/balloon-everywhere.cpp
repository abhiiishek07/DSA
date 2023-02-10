//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        unordered_map<char,int>mp;
        for(char ch:s)
        mp[ch]++;
        
        string str="balloon";
        int ans=INT_MAX;
        for(char ch:str){
            if(ch=='l' || ch=='o')
            ans=min(ans,mp[ch]/2);
            else
            ans=min(ans,mp[ch]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends