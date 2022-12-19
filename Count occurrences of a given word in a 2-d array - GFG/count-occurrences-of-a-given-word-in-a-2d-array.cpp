//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int getCount(int i,int j,int idx,vector<vector<char>>&mat,string target){
        if(i<0||j<0||i>=mat.size()||j>=mat[0].size()||mat[i][j]!=target[idx])
        return 0;
        if(idx==target.size()-1)
        return 1;
        int cnt=0;
        char ch=mat[i][j];
        mat[i][j]='*';
        cnt+= getCount(i+1,j,idx+1,mat,target);
        cnt+= getCount(i-1,j,idx+1,mat,target);
        cnt+= getCount(i,j+1,idx+1,mat,target);
        cnt+= getCount(i,j-1,idx+1,mat,target);
        
        mat[i][j]=ch;
        return cnt;
    }
    int findOccurrence(vector<vector<char> > &mat, string target){
        int ans=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                ans+= getCount(i,j,0,mat,target);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<vector<char> > mat(R);
        for (int i = 0; i < R; i++) {
            mat[i].resize(C);
            for (int j = 0; j < C; j++) cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout<<obj.findOccurrence(mat,target)<<endl;
    }
}

// } Driver Code Ends