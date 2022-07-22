class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        priority_queue<pair<int,int>>pq1;
        for(int i=0;i<difficulty.size();i++)
            pq1.push({profit[i],difficulty[i]});
        priority_queue<int>pq2;
        for(int x:worker)
            pq2.push(x);
        int ans=0;
        while(!pq1.empty() && !pq2.empty()){
           if(pq1.top().second<=pq2.top()){
               ans+= pq1.top().first;
               pq2.pop();
           }
            else
                pq1.pop();
        }
        return ans;
    }
};