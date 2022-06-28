class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int mx=max_element(nums.begin(),nums.end())-nums.begin();//index of maximum element
        int mn=min_element(nums.begin(),nums.end())-nums.begin();//index of minimum element
        
        int maxi=max(mx,mn);           //largest index
        int mini=min(mx,mn);           // smallest index
        
        int op1= n-mini;               //option1: delete from last only till smallest index
        int op2= maxi+1;               //option2: delete from front only till largest index
        int op3= (n-maxi)+(mini+1);    //option3: delete from front and back both
        
        int ans=min(op1,(min(op2,op3)));
        return ans;
        
    }
};