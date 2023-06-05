//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here.
            string ans;
            int i=0;
            while(i<s.size()){
                if(isdigit(s[i])){
                    string t="";
                    while(i<s.size() && isdigit(s[i])){
                        t+=s[i++];
                    }
                    ans=t+ans;
                }
                ans=s[i]+ans;
                i++;
            }
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends