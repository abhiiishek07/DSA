class Solution {
public:
    string smallestNumber(string pattern) {
        string ans="";
        stack<int>st;
        int i;
        for(i=0;i<pattern.size();i++){
            st.push(i+1);
            if(pattern[i]=='I'){
                while(!st.empty()){
                    ans+=to_string(st.top());
                    st.pop();
                }
            }
        }
        st.push(i+1);
        while(!st.empty()){
             ans+=to_string(st.top());
             st.pop();
        }
        return ans;
    }
};