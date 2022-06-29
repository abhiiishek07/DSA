class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int ans=0,n=piles.size();
        int i=n-2;
        while(i>=n/3){
            ans+= piles[i];
            i-=2;
        }
        return ans;
    }
};