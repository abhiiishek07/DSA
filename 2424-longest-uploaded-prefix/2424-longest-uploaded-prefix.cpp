class LUPrefix {
public:
    map<int,int>mp;
    int i=1;
    LUPrefix(int n) {
        mp.clear();
    }
    
    void upload(int video) {
        if(i==video)
            i++;
        mp[video]++;
    }
    
    int longest() {
        int cnt=i-1;
      while(mp.find(i)!=mp.end()){
          i++;
          cnt++;
      }
        return cnt;
   
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */