class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        priority_queue<int,vector<int>,greater<int>>pq;
        int i=1,ans=0;
        while(i<colors.size()){
            if(colors[i]==colors[i-1]){
                pq.push(neededTime[i-1]);
                pq.push(neededTime[i]);
                int j=i+1;
                while(j<colors.size() && colors[j]==colors[j-1]){
                    pq.push(neededTime[j]);
                    j++;
                }
                while(pq.size()>1){
                    ans+=pq.top();
                    pq.pop();
                }
                i=j;
                pq.pop();
            }
            else
                i++;
        }
        return ans;
    }
};