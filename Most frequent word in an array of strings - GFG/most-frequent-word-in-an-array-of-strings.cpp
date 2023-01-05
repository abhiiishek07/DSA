//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
    public:
    //Function to find most frequent word in an array of strings.
    string mostFrequentWord(string arr[], int n) 
    {
        // code here
        unordered_map<string,pair<int,int>>mp;
        for(int i=0;i<n;i++){
            string word= arr[i];
            mp[word].first++;
           if(mp[word].first==1)
           mp[word].second=i;
        }
        string ans;
        int freq=0, ind=-1;
        for(auto it:mp){
            int f=it.second.first, i=it.second.second;
            if(f==freq && i>ind){
                ans=it.first;
                ind=i;
            }
            else if(f>freq){
                ans=it.first;
                ind=i;
                freq=f;
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
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.mostFrequentWord(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends