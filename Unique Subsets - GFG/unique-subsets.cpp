//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    set<vector<int>>s;
    void solve(vector<int>arr,int idx,int n,vector<int>temp,vector<vector<int>>&ans){
        if(idx==n){
            sort(temp.begin(),temp.end());
           s.insert(temp);
            return;
        }
        temp.push_back(arr[idx]);
        solve(arr,idx+1,n,temp,ans);
        temp.pop_back();
        solve(arr,idx+1,n,temp,ans);
        
        
    }
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // code here
        vector<vector<int>>ans;
        vector<int>temp;
        solve(arr,0,n,temp,ans);
        for(auto x:s){
            ans.push_back(x);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   



// } Driver Code Ends