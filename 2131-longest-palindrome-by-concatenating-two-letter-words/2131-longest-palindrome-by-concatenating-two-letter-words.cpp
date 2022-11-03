class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans=0;
        unordered_map<string,int>mp;
        for(string str:words){
            mp[str]++;
        }
        bool flag=false;
        for(auto it:mp){
            string str=it.first;
            if(str[0]==str[1]){
                if(it.second%2){
                    it.second--;
                    flag=true;
                }
                ans+= it.second;
            }
            else if(str[0]<str[1]){
                string temp=str;
                reverse(temp.begin(),temp.end());
                if(mp.find(temp)!=mp.end())
                ans+= min(it.second,mp[temp])*2;
            }
        }
        if(flag)
            ans++;
        return ans*2;
    }
};