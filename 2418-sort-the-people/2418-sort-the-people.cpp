class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int,string>mp;
        for(int i=0;i<heights.size();i++){
            mp[heights[i]]=names[i];
        }
        sort(heights.begin(),heights.end(),greater<int>());
        vector<string>ans;
        for(int x:heights){
            ans.push_back(mp[x]);
        }
        return ans;
    }
};