class Solution {
public:
    int balancedStringSplit(string s) {
        int l=0,r=0,ans=0;
        for(char ch:s){
            ch=='L' ? l++:r++;
            if(l==r){
                ans++;
                l=0,r=0;
            }
        }
        return ans;
    }
};