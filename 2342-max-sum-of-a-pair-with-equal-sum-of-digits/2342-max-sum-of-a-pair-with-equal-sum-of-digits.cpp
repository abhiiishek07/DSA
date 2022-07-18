class Solution {
public:
    int digitSum(long long int n){
        long long int s=0;
        while(n>0){
            s+= n%10;
            n/=10;
        }
        return s;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,priority_queue<int>>mp;
        for(long long int x:nums){
            long long int y= digitSum(x);
            mp[y].push(x);
        }
        long long int ans=-1;
        for(auto it:mp){
            if(it.second.size()>=2){
                long long int a=it.second.top();
                it.second.pop();
                long long int b=it.second.top();
                ans=max(ans,a+b);
            }
        }
        return (int)ans;
    }
};