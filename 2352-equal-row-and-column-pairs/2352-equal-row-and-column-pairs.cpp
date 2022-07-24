class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<grid.size();i++){
            vector<int>v;
            for(int j=0;j<grid.size();j++)
                v.push_back(grid[i][j]);
            mp[i]=v;
            v.clear();
        }
        int ans=0;
        for(int i=0;i<grid.size();i++){
            vector<int>v;
            for(int j=0;j<grid.size();j++)
                v.push_back(grid[j][i]);
            for(auto it:mp){
                if(it.second==v)
                    ans++;
            }
        }
        return ans;
    }
};