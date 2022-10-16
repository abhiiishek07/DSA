class Solution {
public:
    int countTime(string time) {
        int ans=1;
        time[4]=='?' ? ans*=10:ans*=1;
        time[3]=='?' ? ans*=6:ans*=1;
        if(time[0]=='?' && time[1]=='?')
            ans*=24;
        else{
            if(time[1]=='?'){
                if(time[0]=='2')
                    ans*=4;
                else
                    ans*=10;
            }
            else if(time[0]=='?'){
                if(time[1]<'4')
                    ans*=3;
                else
                    ans*=2;
            }
        }
        return ans;
    }
};