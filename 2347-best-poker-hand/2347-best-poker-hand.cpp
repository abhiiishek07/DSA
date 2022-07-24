class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        unordered_set<char>s(suits.begin(),suits.end());
        if(s.size()==1)
            return "Flush";
        unordered_map<int,int>mp;
        for(int x:ranks)
            mp[x]++;
        bool three=false,pair=false;
        for(auto it:mp){
            if(it.second>=3){
                three=true;
                break;
            }
            else if(it.second>=2){
                pair=true;
            }
        }
        if(three)
            return "Three of a Kind";
        else if(pair)
            return "Pair";
        return
            "High Card";
        
    }
};