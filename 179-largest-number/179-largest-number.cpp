class Solution {
public:
    static bool comp(string &a,string &b){
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>v;
        for(int x:nums){
            v.push_back(to_string(x));
        }
        sort(v.begin(),v.end(),comp);
        string ans;
        for(string s:v){
            ans+=s;
        }
        if(ans[0]=='0')
            return "0";
        return ans;
        
    }
};