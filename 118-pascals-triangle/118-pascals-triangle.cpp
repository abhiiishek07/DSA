class Solution {
public:
    vector<vector<int>> solve(int id,int n,vector<int>prev,vector<vector<int>> &ans){
        if(id==n+1)
            return ans;
        vector<int>v;
        for(int i=0;i<id;i++){
            if(i==0 || i==id-1)
                v.push_back(1);
            else
                v.push_back(prev[i]+prev[i-1]);
        }
        ans.push_back(v);
        return solve(id+1,n,v,ans);
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        vector<int>prev;
        return solve(1,numRows,prev,ans);
    }
};