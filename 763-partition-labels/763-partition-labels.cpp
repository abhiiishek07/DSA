class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        int pos=0;
        for(char ch:s)
            mp[ch]=pos++;
        int maxParti=INT_MIN,prev=0;
        vector<int>ans;
        for(int i=0;i<s.size();i++){
            maxParti=max(maxParti,mp[s[i]]);
            if(maxParti==i){
                ans.push_back(maxParti-prev+1);
                prev=i+1;
            }
        }
        return ans;
    }
};