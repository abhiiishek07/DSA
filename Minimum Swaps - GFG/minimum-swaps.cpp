//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimumSwaps(int c[],int v[],int n,int k,int b,int T)
    {
            // code 
            vector<double>times(n);
            double t=T;
            for(int i=0;i<n;i++){
                // times[i]=((double)(b-c[i]))/((double)v[i]);
                times[i]=(b-c[i])/v[i];
            }
            int ans=0,i=n-1;
            while(i>=0){
                if(times[i]<=t){
                    k--;
                    i--;
                    if(k==0)
                    break;
                }
                else{
                    int prev=i;
                    bool found=false;
                    while(i>=0 && times[i]>t){
                        i--;
                    }
                    if(i<0) break;
                    
                    swap(times[i],times[prev]);
                    ans+= (prev-i);
                    i=prev;
                }
            }
            if(k>0) return -1;
            return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t=1,testcases=1;
    cin>>t;
    while(t>=testcases)
    {
        int n,k,b,T;
        cin>>n>>k>>b>>T;
        int c[n];
        int v[n];
        for(auto &j:c)
            cin>>j;
        for(auto &j:v)
            cin>>j;
        Solution s;
        int ans=s.minimumSwaps(c,v,n,k,b,T);
        cout<<ans<<endl;
        testcases++;
    }
    // TIME;
    return 0;
}
// } Driver Code Ends