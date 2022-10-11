//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
        stack<string>st;
        int i=0;
        while(i<s.length()){
            if(isdigit(s[i])){
                string temp="";
                while(s[i]!='['){
                    temp+=s[i];
                    i++;
                }
                st.push(temp);
                temp="";
                temp+=s[i];
                st.push(temp);
                i++;
            }
            else if(s[i]==']'){
                string temp="";
                while(st.top()!="["){
                    temp=st.top()+temp;
                    st.pop();
                }
                st.pop();
                int n=stoi(st.top());
                st.pop();
                string str=temp;
                for(int j=0;j<n-1;j++)
                temp+=str;
                st.push(temp);
                i++;
            }
            else{
                string temp="";
                temp+=s[i];
                st.push(temp);
                i++;
            }
        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends