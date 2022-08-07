class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int l=i+1;
            while(l<nums.size()){
                if(nums[l]-nums[i]==diff){
                    int h=l+1;
                    while(h<nums.size()){
                        if(nums[h]-nums[l]==diff)
                            cnt++;
                        h++;
                    }
                }
                l++;
            }
        }
        return cnt;
    }
};