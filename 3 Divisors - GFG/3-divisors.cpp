//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<long long>findPrimes(int n){
        vector<long long>prime(n+1,1);
        prime[0]=0;
        prime[1]=0;
        for(int i=2;i<=n;i++){
            if(prime[i]){
                for(int j=i*2;j<=n;j+=i){
                    prime[j]=0;
                }
            }
        }
        return prime;
    }
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        // Write your code here
        long long maxi= *max_element(query.begin(),query.end());
        vector<long long>primes= findPrimes(maxi);
        vector<int>ans;
        for(int num:query){
            int sq=sqrt(num);
            int cnt=0;
            for(int i=2;i<=sq;i++){
                if(primes[i])
                cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends