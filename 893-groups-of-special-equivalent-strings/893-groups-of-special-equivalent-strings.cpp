class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_map<string,int>mp;
        for(string str:words){
            string even,odd;
            for(int i=0;i<str.size();i++){
                if(i%2==0)
                    even+= str[i];
                else
                    odd+= str[i];
            }
            sort(even.begin(),even.end());
            sort(odd.begin(),odd.end());
            string newWord=even+odd;
            mp[newWord]++;
        }
        return mp.size();
    }
};