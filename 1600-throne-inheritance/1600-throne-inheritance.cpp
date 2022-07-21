class ThroneInheritance {
public:
    unordered_map<string,vector<string>>mp;
    unordered_set<string>dead;
    vector<string>order;
    string king;
    ThroneInheritance(string kingName) {
        mp.clear();
        king=kingName;
    }
    
    void birth(string parentName, string childName) {
        mp[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        order.clear();
        solve(king);
        return order;
    }
    void solve(string king){
        if(dead.find(king)==dead.end())
            order.push_back(king);
        for(auto it:mp[king])
            solve(it);
        return;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */