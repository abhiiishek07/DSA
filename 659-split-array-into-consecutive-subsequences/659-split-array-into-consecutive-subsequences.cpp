class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>available;
        unordered_map<int,int>vacancy;
        for(int x:nums){
            available[x]++;
        }
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            if(available[num]<=0)
                continue;
            else if(vacancy[num]>0){
                available[num]--;
                vacancy[num]--;
                vacancy[num+1]++;
            }
            else if(available[num]>0 && available[num+1]>0 && available[num+2]>0){
                available[num]--;
                available[num+1]--;
               available[num+2]--;
                vacancy[num+3]++;
        }
        else
            return false;
    }
    return true;
    }
};