class Solution {
public:
    string convert(vector<string>&words){
        string str;
        for(string word:words)
            str+=word;
        return str;
    }
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        if(convert(word1)==convert(word2))
            return true;
        return false;
    }
};