//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++
class Solution
{
   public:
    string ReFormatString(string S, int K){
    	int i=S.size()-1,cnt=0;
    	string ans;
    	while(i>=0){
    	    if(S[i]!='-'){
    	        cnt++;
    	        ans+= toupper(S[i]);
    	    }
    	    if(cnt==K){
    	        cnt=0;
    	        ans+="-";
    	    }
    	    i--;
    	}
    	reverse(ans.begin(),ans.end());
    	while(ans.size() && ans[0]=='-')
    	ans.erase(ans.begin()+0);
    	return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string S;
	    cin>>S;
	    int K;
	    cin >> K;
	    Solution ob;  
	    string ans=ob.ReFormatString(S, K);
	    cout<<ans;
	    cout<<"\n";
	}
	return 0;
}

// } Driver Code Ends