class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int cnt=-1;
        while(true){
            bool flag=false;
            int i=0;
            while(i<s.size()-1){
                if(s[i]=='0' && s[i+1]=='1'){
                    swap(s[i],s[i+1]);
                    i+=2;
                    flag=true;
                }
                else{
                    i++;
                }
            }
            cnt++;
            if(!flag)
                break;
        }
        return cnt;
    }
};