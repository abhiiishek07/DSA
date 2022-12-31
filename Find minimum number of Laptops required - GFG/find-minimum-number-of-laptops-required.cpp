//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    static bool comp(pair<int,int>&a,pair<int,int>&b){
        if(a.first==b.first) return a.second<=b.second;
        return a.first<b.first;
        
    }
    int minLaptops(int N, int start[], int end[]) {
        // Code here
        vector<pair<int,int>>timing;
        for(int i=0;i<N;i++){
            timing.push_back({start[i],end[i]});
        }
        sort(timing.begin(),timing.end(),comp);
        priority_queue<int,vector<int>,greater<int>>pq;
        int laptops=0;
        for(int i=0;i<N;i++){
            if(!pq.empty() && timing[i].first>=pq.top()){
                pq.pop();
            }
            else{
                laptops++;
            }
            pq.push(timing[i].second);
        }
        return laptops;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}
// } Driver Code Ends