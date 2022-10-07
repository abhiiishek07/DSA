class Solution {
public:
    static bool comp(pair<int,int>&a,pair<int,int>&b){
        if(a.first==b.first)
            return a.second<b.second;
        return a.first<b.first;
    }
    int solve(int n,unordered_map<int,int>&dp){
        if(n==1)
            return 0;
        if(dp.find(n)!=dp.end())
            return dp[n];
        int steps=0;
        if(n%2==0)
            steps=1+solve(n/2,dp);
        else
            steps=1+solve(3*n+1,dp);
        return dp[n]=steps;
    }
    int getKth(int lo, int hi, int k) {
        unordered_map<int,int>dp;
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=lo;i<=hi;i++){
            int temp=solve(i,dp);
        }
        vector<pair<int,int>>ans;
        for(int i=lo;i<=hi;i++)
            ans.push_back({dp[i],i});
        sort(ans.begin(),ans.end(),comp);
        return ans[k-1].second;
    }
};