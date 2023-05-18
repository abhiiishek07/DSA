//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    void removeNotClosedIsland(vector<vector<int>>& matrix,int i,int j){
        if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size() || !matrix[i][j]) return;
        matrix[i][j]=0;
        removeNotClosedIsland(matrix,i+1,j);
        removeNotClosedIsland(matrix,i-1,j);
        removeNotClosedIsland(matrix,i,j+1);
        removeNotClosedIsland(matrix,i,j-1);
    }
    void dfs(vector<vector<int>>& matrix,int i,int j){
        if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size() || !matrix[i][j]) return;
        matrix[i][j]=0;
        dfs(matrix,i+1,j);
        dfs(matrix,i,j+1);
        dfs(matrix,i-1,j);
        dfs(matrix,i,j-1);
    }
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        // Code here
        for(int i=0;i<N;i++){
            if(matrix[i][0])
            removeNotClosedIsland(matrix,i,0);
            if(matrix[i][M-1])
            removeNotClosedIsland(matrix,i,M-1);
        }
        for(int j=0;j<M;j++){
            if(matrix[0][j])
            removeNotClosedIsland(matrix,0,j);
            if(matrix[N-1][j])
            removeNotClosedIsland(matrix,N-1,j);
        }
        int cnt=0;
        for(int i=1;i<N-1;i++){
            for(int j=1;j<M-1;j++){
                if(matrix[i][j]){
                    cnt++;
                    dfs(matrix,i,j);
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends