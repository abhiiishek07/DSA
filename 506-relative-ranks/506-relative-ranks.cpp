class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<int>pq(score.begin(),score.end());
        unordered_map<int,string>mp;
        int pos=1;
        while(!pq.empty()){
            if(pos==1)
                mp[pq.top()]="Gold Medal";
            else if(pos==2)
                mp[pq.top()]="Silver Medal";
            else if(pos==3)
                mp[pq.top()]="Bronze Medal";
            else
                mp[pq.top()]=to_string(pos);
            
            pq.pop();
            pos++;
        }
        vector<string>ans;
        for(int x:score){
            ans.push_back(mp[x]);
        }
        return ans;
    }
};