class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,h=height.size()-1,area=INT_MIN;
        while(l<h){
            area=max(area,min(height[l],height[h])*(h-l));  //  area will be min height bw two heights & width
            if(height[l]<height[h])        
                l++;                         // we will only take max height for further answers
            else
                h--;
        }
        return area;
    }
};