class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(int x:arr){
            mp[((x%k)+k)%k]++;
        }
        int i=0;
        while(i<k){
            if(i==0){
                if(mp[0]%2)
                    return false;
            }
            else{
                if(mp[i]!=mp[k-i])
                    return false;
            }
            i++;
        }
        return true;
    }
};