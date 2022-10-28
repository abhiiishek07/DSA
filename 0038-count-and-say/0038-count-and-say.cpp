class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string temp= countAndSay(n-1);
        int cnt=0,sz=temp.size();
        string ans;
        for(int i=0;i<sz;i++){
            cnt++;
            if(i==sz-1 || temp[i]!=temp[i+1]){
                ans+= to_string(cnt)+temp[i];
                cnt=0;
            }
        }
        return ans;
        
    }
};