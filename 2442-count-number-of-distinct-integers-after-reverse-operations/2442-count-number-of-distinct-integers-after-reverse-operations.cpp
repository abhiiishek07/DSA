class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int sz=nums.size();
        for(int i=0;i<sz;i++){
            string str= to_string(nums[i]);
            reverse(str.begin(),str.end());
            nums.push_back(stoi(str));
        }
        unordered_set<int>st(nums.begin(),nums.end());
        return st.size();
    }
};