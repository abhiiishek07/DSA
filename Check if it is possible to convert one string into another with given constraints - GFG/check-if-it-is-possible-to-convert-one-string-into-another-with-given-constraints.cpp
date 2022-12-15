//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isItPossible(string S, string T, int M, int N) {
        // code here
        if(M!=N) return 0;
        vector<pair<char,int>>v1,v2;
        for(int i=0;i<M;i++){
            char ch=S[i];
            if(ch=='A'||ch=='B')
            v1.push_back({ch,i});
        }
           for(int i=0;i<N;i++){
               char ch=T[i];
            if(ch=='A'||ch=='B')
            v2.push_back({ch,i});
        }
        if(v1.size()!=v2.size())
        return false;
        for(int i=0;i<v1.size();i++){
            if(v1[i].first!=v2[i].first)
            return false;
            
            if(v1[i].first=='A' && v1[i].second<v2[i].second)
            return false;
            else if(v1[i].first=='B' && v1[i].second>v2[i].second)
            return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, T;
        cin >> S >> T;
        int M = S.length(), N = T.length();
        Solution ob;
        cout << ob.isItPossible(S, T, M, N);
        cout << "\n";
    }
}
// } Driver Code Ends