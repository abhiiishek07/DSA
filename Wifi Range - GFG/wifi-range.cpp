//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        // code here
        int maxi=0;
        for(int i=0;i<S.size();i++){
                
            if(S[i]=='1')
            maxi=i+X;
            else if(i>0 && S[i]=='0' && maxi>=i)
            S[i]='1';
        
        }
        maxi=S.size()-1;
        for(int i=S.size()-1;i>=0;i--){
            if(S[i]=='1')
            maxi=i-X;
            else if(i<S.size()-1 && S[i]=='0' && maxi<=i)
            S[i]='1';
        }
        for(char ch:S){
            if(ch=='0') return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends