class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>mp;
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        string ans="";
        if(mp.find(key)==mp.end())
            return "";
        else if(mp[key][0].first>timestamp)
            return "";
        else{
            int low=0,high=mp[key].size()-1;
            
            while(low<=high){
                int mid=low+(high-low)/2;
                int t=mp[key][mid].first;
                if(t<=timestamp){
                    ans=mp[key][mid].second;
                    low=mid+1;
                }
                else
                    high=mid-1;
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */