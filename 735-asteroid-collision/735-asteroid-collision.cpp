class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int x:asteroids){
            if(x<0){
                while(!st.empty() && st.top()>0 && abs(x)>st.top())
                    st.pop();
                if(!st.empty() && st.top()==abs(x))
                    st.pop();
                else if(st.empty() || st.top()<0)
                    st.push(x);
            }
            else
                st.push(x);
        }
        int n=st.size();
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};