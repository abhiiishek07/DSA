//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        // code here
        if(N%groupSize==1) return false;
        map<int,int>mp;
        for(int val:hand)
        mp[val]++;
        while(true){
            int k= mp.begin()->first;
            mp[k]--;
            if(mp[k]==0) mp.erase(k);
            int t=groupSize-1;
            while(t--){
                k++;
                if(mp.find(k)==mp.end()) return false;
                mp[k]--;
                if(mp[k]==0) mp.erase(k);
            }
            if(mp.size()==0) break;;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends