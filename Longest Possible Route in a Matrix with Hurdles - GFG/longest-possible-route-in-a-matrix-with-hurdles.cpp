// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int ans=-1;
    void solve(vector<vector<int>> &matrix, int xs, int ys, int xd, int yd, int cnt){
        if(xs<0 || ys<0 || xs>=matrix.size() || ys>=matrix[0].size() || !matrix[xs][ys])
        return;
        
        if(xs==xd && ys==yd){
            ans=max(ans,cnt);
            return;
        }
         matrix[xs][ys]=0;
         
        solve(matrix,xs+1,ys,xd,yd,cnt+1);
        solve(matrix,xs,ys+1,xd,yd,cnt+1);
        solve(matrix,xs-1,ys,xd,yd,cnt+1);
        solve(matrix,xs,ys-1,xd,yd,cnt+1);
        
        matrix[xs][ys]=1;
    }
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        // code here
        if(!matrix[xs][ys] || !matrix[xd][yd])
        return -1;
        int cnt=0;
        solve(matrix,xs,ys,xd,yd,cnt);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends