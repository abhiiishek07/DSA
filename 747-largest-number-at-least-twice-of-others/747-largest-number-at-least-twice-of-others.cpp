class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largest= *max_element(nums.begin(),nums.end());
        int largestIndex=max_element(nums.begin(),nums.end())-nums.begin();
        for(int x:nums){
            if(x!=largest && x*2>largest)
                return -1;
        }
        return largestIndex;
    }
};