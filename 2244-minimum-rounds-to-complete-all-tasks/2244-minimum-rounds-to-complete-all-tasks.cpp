class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<long long,long long>mp;
        for(int x:tasks)
            mp[x]++;
        int ans=0;
        for(auto it:mp){
            int cnt=it.second;
            if(cnt>=2){
                while(cnt>=2){
                    if(cnt>4){
                        ans++;
                        cnt-=3;
                    }
                    if(cnt==4){
                        ans+=2;
                        cnt=0;
                    }
                    else if(cnt==3){
                        ans++;
                        cnt=0;
                    }
                    else if(cnt==2){
                        ans++;
                        cnt=0;
                    }
                }
            }
            else{
                return -1;
            }
        }
        return ans;
    }
};