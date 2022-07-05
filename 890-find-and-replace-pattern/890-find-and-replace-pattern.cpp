class Solution {
public:
    bool check(string str,string pat,unordered_map<char,int>mp){
        unordered_map<char,int>mp2;
        int pos=0;
        for(char ch:str)
            mp2[ch]=pos++;
        if(mp.size()!=mp2.size())
            return false;
        for(int i=0;i<str.size();i++){
            if(mp2[str[i]]!=mp[pat[i]])
                return false;
        }
        return true;
        
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<char,int>mp;
        int pos=0;
        for(char ch:pattern)
            mp[ch]=pos++;
        vector<string>ans;
        for(string str:words){
            if(check(str,pattern,mp))
                ans.push_back(str);
        }
        return ans;
    }
};