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
        vector<int>ans;
        // return ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};