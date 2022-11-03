//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            // code here
            if(s.size()>15) return false;       // max size can be 15
            string num="";
            int n=0,dots=0;
            for(int i=0;i<s.size();i++){
                if(s[i]!='.') {
                if(!isdigit(s[i]))
                return 0;
                num+=s[i];
                }
                if(s[i]=='.' || i==s.size()-1) {
                    if(i==s.size()-1 && s[i]=='.')
                    return 0;
                    if(num.size()==0 || (num[0]=='0' && num.size()>1) || stoi(num)>255)
                    return 0;
                    num="";
                    n++;
                    dots++;
                }
            }
            return n==4 && dots==4;
        }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends