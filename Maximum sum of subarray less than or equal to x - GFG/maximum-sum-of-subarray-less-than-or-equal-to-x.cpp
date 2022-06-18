// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{


	public:
	int findMaxSubarraySum(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    long long sumi=0,i=0,j=0,ans=INT_MIN;
	    while(j<n){
	        sumi+= arr[j];
	        while(sumi>sum){
	            sumi-= arr[i];
	            i++;
	        }
	        ans=max(ans,sumi);
	        j++;
	    }
	    return ans;
	}  

		 

};
	  



// { Driver Code Starts.

int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
    	 int n;
        cin>>n;
        
        long long a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        
        long long sum;
        cin >> sum;
        

        Solution ob;
		cout << ob.findMaxSubarraySum(a, n, sum);
        
	    cout << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends