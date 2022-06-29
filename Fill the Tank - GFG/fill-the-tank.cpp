// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {

public:
    long long solve(vector<long long>adj[],int s,int *cap,vector<long long>&vis){
        long long ans=0,child=0;
        vis[s]=1;
        for(auto it:adj[s]){
            if(!vis[it]){
                child++;
                long long x=solve(adj,it,cap,vis);
                if(x==-1)
                  return -1;
                ans=max(x,ans);
            }
        }
        long long c= cap[s-1]+ans*child;
        if(c>1e18)
          return -1;
        return c;
    }
    long long minimum_amount(vector<vector<int>> &Edges, int N, int S, int *Cap){
       // Code here
       vector<long long>adj[N+1];
       for(auto it:Edges){
           adj[it[0]].push_back(it[1]);
           adj[it[1]].push_back(it[0]);
       }
       vector<long long>vis(N+1,0);
       long long res=solve(adj,S,Cap,vis);
       return res;
    }
};

// { Driver Code Starts.


int main()
 {
	int T;
	cin>> T;
	while (T--)
	{
	    int num, start;
	    cin>>num>>start;
	    int cap[num];
	    for(int i = 0; i<num; i++)
	        cin>>cap[i];
	    
	    vector<vector<int>> Edges(num-1);
	    for(int i=1;i < num;i++){
	        int u, v; cin >> u >> v;
	        Edges[i-1].push_back(u);
	        Edges[i-1].push_back(v);
	    }
	    
	    
    	Solution obj;
	    long long ans = obj.minimum_amount(Edges, num, start, cap);
	    cout << ans << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends