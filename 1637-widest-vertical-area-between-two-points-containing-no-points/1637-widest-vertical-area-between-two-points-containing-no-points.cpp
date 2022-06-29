class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
          vector<int>x;
        for(auto it:points){
            x.push_back(it[0]);
        }
        sort(x.begin(),x.end());
        int ans=INT_MIN;
        for(int i=1;i<x.size();i++){
            ans=max(ans,x[i]-x[i-1]);
        }
        return ans;
        }
};