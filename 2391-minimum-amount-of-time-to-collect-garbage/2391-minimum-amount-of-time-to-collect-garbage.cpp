class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        unordered_map<char,int>mp;
        int ans=0,sum=0;
        mp[0]=0;
        int lp=0,lg=0,lm=0;
        for(int i=0;i<garbage.size();i++){
            string str=garbage[i];
            int m=0,p=0,g=0;
            for(char ch:str){
                if(ch=='M'){
                    m++;
                    lm=i;
                }
                else if(ch=='P'){
                    p++;
                    lp=i;
                }
                else if(ch=='G'){
                    g++;
                    lg=i;
                }
            }
            ans+=m+p+g;
            if(i>0){
            sum+=travel[i-1];
            mp[i]=sum;
            }
        }
        ans+= mp[lp]+mp[lg]+mp[lm];
        return ans;
    }
};