class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int j=0,i=0;
        int sum=0;
        for(int k=0;k<customers.size();k++){
            if(!grumpy[k])
                sum+= customers[k];
        }
        int ans=INT_MIN;
        while(j<customers.size()){
            if(grumpy[j])
                sum+= customers[j];
            if(j-i+1==minutes){
                ans=max(ans,sum);
                if(grumpy[i])
                    sum-= customers[i];
                i++;
                }
            j++;
        }
        return ans;
        
        }
};