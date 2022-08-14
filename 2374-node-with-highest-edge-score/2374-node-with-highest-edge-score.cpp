class Solution {
public:
    int edgeScore(vector<int>& edges) {
        unordered_map<int,long long>mp;
        for(int i=0;i<edges.size();i++){
            mp[edges[i]]+=i;
        }
        int node;
        long long maxScore=INT_MIN;
        for(auto it:mp){
            if(it.second>maxScore){
                maxScore=it.second;
                node=it.first;
            }
            else if(it.second==maxScore){
                node=min(node,it.first);
            }
        }
        return node;
    }
};