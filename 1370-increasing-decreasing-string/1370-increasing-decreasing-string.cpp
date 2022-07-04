class Solution {
public:
    string sortString(string s) {
        string ans="";
        unordered_map<char,int>mp;
        for(char ch:s){
            mp[ch]++;
        }
        while(mp.size()>0){
            priority_queue<char,vector<char>,greater<char>>pq1;
            for(auto it:mp)
                pq1.push(it.first);
            while(!pq1.empty()){
                ans+=pq1.top();
                mp[pq1.top()]--;
                if(mp[pq1.top()]==0)
                    mp.erase(pq1.top());
                pq1.pop();
            }
            priority_queue<char>pq2;
            for(auto it:mp)
                pq2.push(it.first);
            while(!pq2.empty()){
                ans+=pq2.top();
                mp[pq2.top()]--;
                if(mp[pq2.top()]==0)
                    mp.erase(pq2.top());
                pq2.pop();
            }
        }
        return ans;
    }
};