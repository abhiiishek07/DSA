class Solution {
public:
    string reverseWords(string s) {
        string ans="",str="";
        for(char ch:s){
            if(ch==' '){
                ans+=str+' ';
                str="";
            }
            else
                str=ch+str;
        }
        ans+=str;
        return ans;
    }
};