class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mp.find(i-j)==mp.end()){
                    int x=i,y=j;
                    while(x<m && y<n){
                        mp[i-j].push_back(mat[x][y]);
                        x+=1;
                        y+=1;
                    }
                    sort(mp[i-j].begin(),mp[i-j].end());
                }
            }
        }
        vector<vector<int>>ans(m,vector<int>(n,0));
        unordered_set<int>seen;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(seen.find(i-j)==seen.end() && mp.find(i-j)!=mp.end()){
                    int x=i,y=j;
                    for(int num:mp[i-j]){
                        ans[x][y]=num;
                        x+=1;
                        y+=1;
                    }
                    seen.insert(i-j);
                }
            }
        }
        return ans;
        
    }
};