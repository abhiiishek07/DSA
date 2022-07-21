class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<values.size();i++)
            pq.push({values[i],labels[i]});
        unordered_map<int,int>mp;
        int ans=0;
        while(!pq.empty() && numWanted){
            int val= pq.top().first;
            int lab= pq.top().second;
            pq.pop();
            if(mp.find(lab)==mp.end() || mp[lab]<useLimit){
                ans+= val;
                numWanted--;
            }
            mp[lab]++;
        }
        return ans;
    }
};