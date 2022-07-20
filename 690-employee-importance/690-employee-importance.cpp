/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    void solve(int id,unordered_map<int,pair<int,vector<int>>>mp,int &ans){
        ans+= mp[id].first;
        for(auto it:mp[id].second)
            solve(it,mp,ans);
        return;
    }
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,pair<int,vector<int>>>mp;
        for(auto it:employees){
            mp[it->id].first=it->importance;
            mp[it->id].second= it->subordinates;
        }
        int ans=0;
        solve(id,mp,ans);
        return ans;
    }
};