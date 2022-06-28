class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>mp;
        for(char ch:s){
            mp[ch]++;
        }
        unordered_map<int,int>mp2;
        for(auto it:mp){
            mp2[it.second]++;
        }
        vector<int>v;
        for(auto it:mp2){
            v.push_back(it.first);
        }
        sort(v.begin(),v.end());
        int cnt=0;
        for(int i=0;i<v.size();i++){
            while(mp2[v[i]]>1){
                int x=v[i];
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