class Solution {
public:
    void dfs(vector<int>& edges,int src,int dis,unordered_map<int,int>&mp,vector<int>&vis){
        if(src==-1 || vis[src])
            return;
        vis[src]=1;
        mp[src]=dis;
        dfs(edges,edges[src],dis+1,mp,vis);
        return;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        if(node1==node2)
            return node1;
        vector<int>vis1(n+1,0);
        vector<int>vis2(n+1,0);
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        dfs(edges,node1,0,mp1,vis1);
        dfs(edges,node2,0,mp2,vis2);
        int dis=INT_MAX;
        int node=-1;
        for(int i=0;i<edges.size();i++){
            if(mp1.find(i)!=mp1.end() && mp2.find(i)!=mp2.end()){
                    int res=max(mp1[i],mp2[i]);
                    if(dis>res){
                        dis=res;
                        node=i;
                }
            }
        }
        return node;
    }
};