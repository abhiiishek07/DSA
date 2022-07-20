class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string,int>mp;
        for(string str:words){
            mp[str]++;
        }
        int ans=0;
        for(auto it:mp){
            string str=it.first;
            int i=0,j=0;
            while(i<s.length()){
                if(s[i]==str[j])
                    j++;
                i++;
                if(j==str.length()){
                    ans+= it.second;
                    break;
                }
            }
            
        }
        return ans;
    }
};