class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int diff=INT_MAX,ans=INT_MAX,n=nums.size();
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(abs(sum-target)<diff){
                    ans=sum;
                    diff=abs(sum-target);
                }
                if(sum<target)
                    j++;
                else
                    k--;
            }
        }
        return ans;
    }
};