class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>mp;       //frequency of each character
        for(char ch:s){
            mp[ch]++;
        }
        unordered_map<int,int>mp2;     // frequency of each character's freq(how many times)
        for(auto it:mp){
            mp2[it.second]++;
        }
        int cnt=0;
        for(auto it:mp2){
            while(mp2[it.first]>1){
                int x=it.first;
                mp2[x]--;
                while(mp2.find(x)!=mp2.end()){
                    cnt++;
                    x--;
                }
                if(x>0)
                    mp2[x]++;
            }
        }
        return cnt;
    }
};