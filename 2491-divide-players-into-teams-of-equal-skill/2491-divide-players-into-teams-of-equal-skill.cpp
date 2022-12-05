class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        unordered_map<long long,long long>mp;
        long long sum=0;
        for(int num:skill){
            sum+=num;
            mp[num]++;
        }
        unordered_set<int>seen;
        int n= skill.size();
        if(sum%(n/2))
            return -1;
        long long teamSkill= sum/(n/2);
        long long chemistry=0;
        int cnt=0;
        for(int num:skill){
            if(mp.find(teamSkill-num)!=mp.end() && mp.find(num)!=mp.end()){
                cnt++;
                chemistry+= ((teamSkill-num)*num);
                mp[teamSkill-num]--;
                if(mp[teamSkill-num]==0)
                    mp.erase(teamSkill-num);
                mp[num]--;
                if(mp[num]==0)
                    mp.erase(num); 
                 if(cnt==n/2)
                return chemistry;
            }
        }
        return -1;
    }
};