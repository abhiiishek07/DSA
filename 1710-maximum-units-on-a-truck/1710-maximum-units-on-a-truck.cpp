class Solution {
public: 
    
    static bool myComp(vector<int>&a,vector<int>&b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),myComp);
        int ans=0;
        for(auto it:boxTypes){
            if(truckSize<=0)
                break;
           if(truckSize>=it[0]){
               ans+= it[0]*it[1];
               truckSize-= it[0];
           } 
            else{
                ans+= truckSize*it[1];
                truckSize-= it[0];
            }
        }
        return ans;
    }
};