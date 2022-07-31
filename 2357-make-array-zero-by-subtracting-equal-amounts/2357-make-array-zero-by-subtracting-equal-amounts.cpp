class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int>st;
        for(int x:nums){
            if(x>0)
                st.insert(x);
        }
        return st.size();
    }
};
/* Accepted
    int minimumOperations(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int x:nums){
            if(x>0)
                pq.push(x);
        }
        int cnt=0;
        while(!pq.empty()){
            int s=pq.top();
            pq.pop();
            cnt++;
            priority_queue<int,vector<int>,greater<int>>pq2;
            while(!pq.empty()){
                int x=pq.top();pq.pop();
                if(x-s >0)
                    pq2.push(x-s);
            }
           while(!pq2.empty()){
               pq.push(pq2.top());
               pq2.pop();
           }
        }
        return cnt;
    }
};
*/