class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        vector<int>preSum;
        int sum=0;
        for(int x:nums){
            sum+=x;
            preSum.push_back(sum);
        }
        for(int x:queries){
            int cnt=0;
            for(int y:preSum){
                if(y<=x)
                    cnt++;
                else
                    break;
            }
            ans.push_back(cnt);  
        }
        return ans;
    }
};