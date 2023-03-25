//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        // Your code goes here
       vector<int>neg;
       int last=0;
       for(int i=0;i<n;i++){
           if(arr[i]<0){
               neg.push_back(arr[i]);
            //   last=i;
           }
           else arr[last++]=arr[i];
       }
       int k=0;
       for(int i=last;i<n;i++){
           arr[i]=neg[k++];
       }
    }
};

//{ Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}

// } Driver Code Ends