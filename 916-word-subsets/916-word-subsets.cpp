class Solution {
public:
    void freq(string str,vector<int>&count){
        for(char ch:str)
            count[ch-'a']++;
        return;
    }
    bool isSubset(string str, vector<int>words2Freq){
        vector<int>freq(26,0);
        for(char ch:str)
            freq[ch-'a']++;
        for(int i=0;i<26;i++){
            if(freq[i]<words2Freq[i])
                return false;
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>words2Freq(26,0);
        for(string str:words2){
            vector<int>count(26,0);
            freq(str,count);
           for(int i=0;i<26;i++){
               words2Freq[i]=max(words2Freq[i],count[i]);
           }
        }
        vector<string>ans;
       for(string str:words1){
           if(isSubset(str,words2Freq)){
               ans.push_back(str);
           }
       }
        return ans;
    }
};