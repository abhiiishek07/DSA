class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        for(char ch:s)
            freq[ch]++;
        priority_queue<pair<int,char>>pq;
        for(auto it:freq)
            pq.push({it.second,it.first});
        string ans;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int n=it.first;
            char ch=it.second;
            while(n--)
                ans+=ch;
        }
        return ans;
    }
};