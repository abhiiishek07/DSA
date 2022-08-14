class Solution {
public:
    int edgeScore(vector<int>& edges) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<edges.size();i++){
            mp[edges[i]].push_back(i);
        }
        long long score=INT_MIN;
        int node;
        for(auto it:mp){
            long long sum=0;
            for(int x:it.second){
                sum+=x;
            }
            if(sum>score){
                score=sum;
                node=it.first;
            }
            else if(sum==score){
                node=min(node,it.first);
            }
        }
        return node;
    }
};