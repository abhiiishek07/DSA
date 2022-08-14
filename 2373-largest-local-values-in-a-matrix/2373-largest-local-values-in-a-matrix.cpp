class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>ans(n-2,vector<int>(n-2));
        int row=0,col=0;
        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-2;j++){
                int num=INT_MIN;
                for(int p=i;p<i+3;p++){
                    for(int q=j;q<j+3;q++)
                        num=max(num,grid[p][q]);
                }
                ans[i][j]=num;
            }
        }
        return ans;
    }
};