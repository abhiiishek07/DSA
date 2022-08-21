class Solution {
public:
    string largestPalindromic(string num) {
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>>pq;
        for(char ch:num){
            mp[ch-'0']++;
        }
        for(auto it:mp){
            pq.push({it.first,it.second});
        }
        string front,back;
        bool flag=true;
        int middle;
        while(!pq.empty()){
            int x=pq.top().first;
            int y=pq.top().second;
            pq.pop();
            if(flag && y%2){
                if(front.size()==0 && x==0)
                        continue;
                middle=x;
                y--;
                 flag=false;
                for(int i=1;i<=y/2;i++){
                    front+= to_string(x);
                    back+=to_string(x);
                }
               
            }
            else if(y%2==0){
                 if(front.size()==0 && x==0)
                        continue;
                for(int i=1;i<=y/2;i++){
                    front+= to_string(x);
                    back+=to_string(x);
                }
            }
            else if(y%2){
                y--;
                if(front.size()==0 && x==0)
                        continue;
                for(int i=1;i<=y/2;i++){
                    front+= to_string(x);
                    back+=to_string(x);
                }
            }
        }
        reverse(back.begin(),back.end());
        string ans;
        ans+=front;
        if(!flag)
            ans+=to_string(middle);
        ans+=back;
        if(ans.size()==0)
            return "0";
        return ans;
    }
};