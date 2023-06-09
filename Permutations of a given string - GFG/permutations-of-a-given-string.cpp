//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void solve(int i,string s,set<string>&st){
	        if(i==s.size())
	        st.insert(s);
	        
	        for(int k=i;k<s.size();k++){
	            swap(s[i],s[k]);
	            solve(i+1,s,st);
	            swap(s[i],s[k]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    set<string>st;
		    solve(0,S,st);
		    vector<string>ans;
		    for(auto it:st)
		    ans.push_back(it);
		    
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends