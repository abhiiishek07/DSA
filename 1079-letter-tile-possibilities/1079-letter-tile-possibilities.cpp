class Solution {
public:
    unordered_set<string>ans;
    unordered_map<int,int>vis;
    void solve(string tiles,string str){
        for(int i=0;i<tiles.size();i++){
            if(!vis[i]){
                str.push_back(tiles[i]);
                ans.insert(str);
                vis[i]=1;
                solve(tiles,str);
                
                vis[i]=0;
                str.pop_back();
            }
        }
        return;
    }
    int numTilePossibilities(string tiles) {
        solve(tiles,"");
        return ans.size();
    }
};