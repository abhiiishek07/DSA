class Solution {
public:
    bool canChange(string start, string target) {
        queue<pair<char,int>>q1;
        queue<pair<char,int>>q2;
        for(int i=0;i<start.size();i++){
            if(start[i]=='L' || start[i]=='R')
                q1.push({start[i],i});
            if(target[i]=='L' || target[i]=='R')
                q2.push({target[i],i});
        }
        if(q1.size()!=q2.size())
            return false;
        while(!q1.empty() && !q2.empty()){
            auto it1= q1.front();
            q1.pop();
            auto it2= q2.front();
            q2.pop();
            if(it1.first!=it2.first)
                return false;
            else if(it1.first=='L' && it1.second<it2.second)
                return false;
            else if(it1.first=='R' && it1.second>it2.second)
                return false;
        }
        return true;
        
    }
};