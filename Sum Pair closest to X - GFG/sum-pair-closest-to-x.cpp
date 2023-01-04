//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    vector<int> sumClosest(vector<int>arr, int x)
    {
        // code here
        int low=0,high=arr.size()-1,closeSum=0,diff=INT_MAX;
        int numA=-1,numB=-1;
        while(low<high){
            int sum=arr[low]+arr[high];
            int d=abs(sum-x);
            if(d<=diff){
                if(d==diff && sum>closeSum){
                    numA= arr[low];
                    numB= arr[high];
                }
                else if(d<diff){
                    diff=d;
                    numA= arr[low];
                    numB= arr[high];
                    closeSum=sum;
                }
            }
            if(sum<=x)
            low++;
            else
            high--;
        }
        return {numA,numB};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumClosest(arr, x);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends