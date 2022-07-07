class Solution {
public:
	bool solve(int i,int j,int k,string& s1,string& s2,string& s3,int n,int m,int r,vector<vector<int>>& dp){
		if(i>=n && j>=m && k>=r) return true;
		if(k>=r) return false;
		
		if(dp[i][j]!=-1) return dp[i][j];
		
		
		if(i<n && j<m && k<r){
				if(s1[i]==s3[k] && s2[j]==s3[k]) return dp[i][j] = (solve(i+1,j,k+1,s1,s2,s3,n,m,r,dp) || solve(i,j+1,k+1,s1,s2,s3,n,m,r,dp));
		}
		if(i<n && k<r){
			if(s1[i]==s3[k]) return dp[i][j] = solve(i+1,j,k+1,s1,s2,s3,n,m,r,dp);
		}
		if(j<m && k<r){
			if(s2[j]==s3[k]) return dp[i][j] = solve(i,j+1,k+1,s1,s2,s3,n,m,r,dp);
		}
		
		return dp[i][j] = false;
		
	}
	bool isInterleave(string s1, string s2, string s3) {
		int n=s1.size(),m=s2.size(),r=s3.size();
		vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
		return solve(0,0,0,s1,s2,s3,n,m,r,dp);
	}
};