class Solution {
public:
    void nextPermutation(vector<int>& nums) {
                int i=nums.size()-2;
        while(i>=0 && nums[i]>=nums[i+1])
            i--;
        if(i<0){
            reverse(nums.begin(),nums.end());   // if the number is already descending
        }
        else{
        int j=nums.size()-1;
        while(i>=0 && nums[i]>=nums[j])         
            j--;
        swap(nums[i],nums[j]);
        sort(nums.begin()+i+1,nums.end());
    }
    }
};