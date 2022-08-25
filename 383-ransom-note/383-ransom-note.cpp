class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>hash(26,0);
        for(char ch:magazine)
            hash[ch-'a']++;
        for(char ch:ransomNote){
            hash[ch-'a']--;
            if(hash[ch-'a']<0)
                return false;
        }
        return true;
    }
};