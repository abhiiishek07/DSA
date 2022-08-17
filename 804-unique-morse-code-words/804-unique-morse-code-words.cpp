class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
    vector<string>hash={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string>st;
        int cnt=0;
        for(string str:words){
            string s;
            for(char ch:str){
                s+= hash[ch-'a'];
            }
st.insert(s);
        }
        return st.size();
    }
};