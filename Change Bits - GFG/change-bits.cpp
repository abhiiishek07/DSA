// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> changeBits(int N) {
        // code here
        int t=N;
        int newNum=0,idx=0;
        while(t>0){
            newNum+= pow(2,idx++)*1;
            t/=2;
        }
        vector<int>ans;
        ans.push_back(newNum-N);
        ans.push_back(newNum);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        Solution ob;
        auto ans = ob.changeBits(N);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends