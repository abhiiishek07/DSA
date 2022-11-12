//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int characterReplacement(string s, int k){
		    // Code here
		    unordered_map<char,int>mp;
		    int ans=0,i=0,j=0;
		    int maxFreq=0;
		    while(j<s.size()){
		        mp[s[j]]++;
		        maxFreq= max(maxFreq,mp[s[j]]);
		        int len= j-i+1;
		        if(len-maxFreq<=k){
		            ans=max(ans,len);
		        }
		        else{
		            mp[s[i]]--;
		            i++;
		        }
		        j++;
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends