class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        string str;
        unordered_map<int,int>mp;
        unordered_map<string,int>mp2;
        int i=0,j=0,ans=0;
        while(j<s.size()){
            str+= s[j];
            mp[s[j]]++;
            while(mp.size()>maxLetters || str.size()>minSize){
                mp[s[i]]--;
                str.erase(str.begin());
                if(mp[s[i]]==0)
                    mp.erase(s[i]);
                i++;
            }
            if(mp.size()<=maxLetters && str.size()>=minSize && str.size()<=maxSize)
                mp2[str]++;
            j++;
        }
        for(auto it:mp2){
            ans=max(ans,it.second);
        }
        return ans;
    }
};