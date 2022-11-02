class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string,pair<long long int,pair<long long int,string>>>mp;
        long long int maxView= INT_MIN;
        for(int i=0;i<creators.size();i++){
            string creator=creators[i];
            string id= ids[i];
            int view= views[i];
            if(mp.find(creator)==mp.end()){
                mp[creator]={view,{view,id}};
                 maxView=max(maxView,mp[creator].first);
            }
            else {
                mp[creator].first+= view;
                maxView=max(maxView,mp[creator].first);
                if(mp[creator].second.first==view){
                    if(mp[creator].second.second>id)
                        mp[creator].second.second=id;
                }
                else if(mp[creator].second.first<view){
                    mp[creator].second.second=id;
                    mp[creator].second.first=view;
                }
            }
        }
        vector<vector<string>>ans;
        for(auto it: mp){
            if(it.second.first==maxView){
                vector<string>temp= {it.first,it.second.second.second};
                ans.push_back(temp);
            }
        }
        return ans;
        
    }
};