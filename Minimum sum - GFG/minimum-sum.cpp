//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string solve(int arr[], int n) {
        // code here
        sort(arr,arr+n);
        vector<int>a,b;
        for(int i=0;i<n;i++){
            if(i%2==0)
            a.push_back(arr[i]);
            else
            b.push_back(arr[i]);
        }
        string ans;
        int i=a.size()-1,j=b.size()-1,carry=0;
        while(i>=0 || j>=0 || carry){
            int sum=0;
            if(i>=0){
                sum+= a[i--];
            }
            if(j>=0){
                sum+= b[j--];
            }
            sum+= carry;
            ans+= to_string(sum%10);
            carry=sum/10;
        }
       while(ans.size()>1 && ans[ans.size()-1]=='0')
       ans.pop_back();
       
       reverse(ans.begin(),ans.end());
       
       return ans;
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends