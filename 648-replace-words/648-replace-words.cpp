class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        vector<string>words;
        string str;
        for(char ch:sentence){
            if(ch==' '){
                words.push_back(str);
                str="";
            }
            else
                str+=ch;
        }
        words.push_back(str);
        unordered_map<string,int>mp;
        for(string str:dictionary)
            mp[str]++;
        
        string ans;
        for(string str:words){
            string s;
            for(char ch:str){
                s+= ch;
                if(mp.find(s)!=mp.end())
                    break;
            }
            ans+=s;
            ans+=" ";
        }
        ans.pop_back();                           // removing the last added space
        return ans;
    }
};