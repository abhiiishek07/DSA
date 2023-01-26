//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        string upper,lower;
        for(char ch:str){
            if(isupper(ch))
            upper+=ch;
            else
            lower+=ch;
        }
        sort(upper.begin(),upper.end());
        sort(lower.begin(),lower.end());
        string ans;
        int i=0,j=0;
        for(char ch:str){
            if(isupper(ch))
            ans+=upper[i++];
            else
            ans+=lower[j++];
        }
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
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends