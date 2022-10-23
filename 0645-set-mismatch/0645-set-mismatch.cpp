class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int repeated;
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i])-1]<0)
                repeated=abs(nums[i]);
            else
                nums[abs(nums[i])-1]*=-1;
        }
        int lost;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                lost=i+1;
                break;
            }
        }
        return {repeated,lost};
    }
};