class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char,int>mp1,mp2;
        for(char ch:word1)
            mp1[ch]++;
        for(char ch:word2){
            if(mp1.find(ch)==mp1.end())
                return false;
            mp2[ch]++;
        }
            
        unordered_map<int,int>freq;
        for(auto it:mp1)
            freq[it.second]++;
        for(auto it:mp2){
            if(freq.find(it.second)==freq.end())
                return false;
            freq[it.second]--;
            if(freq[it.second]==0)
                freq.erase(it.second);
        }
        return freq.size()==0;
    }
};