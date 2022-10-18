class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int,vector<int>>mp;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        vector<int>ans;
        int level=1;
        for(auto it:mp){
            if(level%2)
                reverse(it.second.begin(),it.second.end());
            for(int x:it.second)
                ans.push_back(x);
            level++;
        }
        
        return ans;
    }
};