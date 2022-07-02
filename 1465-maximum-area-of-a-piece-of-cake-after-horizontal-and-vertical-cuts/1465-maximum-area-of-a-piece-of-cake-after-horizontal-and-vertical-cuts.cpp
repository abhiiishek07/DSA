class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        int maxHori=horizontalCuts[0]-0;
        for(int i=1;i<horizontalCuts.size();i++){
            maxHori=max(maxHori,horizontalCuts[i]-horizontalCuts[i-1]);
        }
        maxHori=max(maxHori,h-horizontalCuts[horizontalCuts.size()-1]);
        
        int maxVerti=verticalCuts[0]-0;
        for(int i=1;i<verticalCuts.size();i++){
            maxVerti=max(maxVerti,verticalCuts[i]-verticalCuts[i-1]);
        }
        maxVerti=max(maxVerti,w-verticalCuts[verticalCuts.size()-1]); 
        
        return ((long long)maxVerti*maxHori)%1000000007;
    }
};