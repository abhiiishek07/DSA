// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        //code here.
        int i=0,j=0,ans=0;
        unordered_set<int>st(arr,arr+n);
        int k=st.size();
        unordered_map<int,int>mp;
        while(j<n){
            mp[arr[j]]++;
            while(mp.size()>=k && i<=j){
                ans+= n-j;
                mp[arr[i]]--;
                if(mp[arr[i]]==0)
                mp.erase(arr[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends