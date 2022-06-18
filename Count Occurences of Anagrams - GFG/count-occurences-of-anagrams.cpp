// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    unordered_map<char,int>mp;
	    for(char ch:pat)
	    mp[ch]++;
	    
	    unordered_map<char,int>mt;
	    int i=0,j=0,cnt=0;
	    while(j<txt.length()){
	        mt[txt[j]]++;
	        if(j-i+1==pat.size()){
	            if(mp==mt)
	            cnt++;
	            mt[txt[i]]--;
	            if(mt[txt[i]]==0)
	            mt.erase(txt[i]);
	            i++;
	        }
	        j++;
	    }
	    return cnt;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends