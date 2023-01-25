//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        // code here
        int ans=s.size();
        string str;
        for(int i=0;i<s.size()/2;i++){
            str+=s[i];
            int n=i+1,j=i+1;
            string temp;
            while(n--){
                temp+=s[j++];
            }
            if(str==temp){
                ans=s.size()-str.size()+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends