class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int>vis(n+1,0);
        queue<int>q;
        q.push(start);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            vis[curr]=1;
            if(arr[curr]==0)
                return true;
            
            int left= curr-arr[curr];
            int right= curr+arr[curr];
            
            if(left>=0 && !vis[left] )
                q.push(left);
            if(right<=n-1 && !vis[right])
                q.push(right);
        }
        return false;
        
    }
};