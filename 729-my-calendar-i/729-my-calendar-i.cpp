class MyCalendar {
public:
    map<int,int>mp;
    MyCalendar() {
        mp.clear();
    }
    
    bool book(int start, int end) {
      auto it=mp.upper_bound(start);
        
     /* Two case: suppose we have already added [10,20] in map
     
       if min end time greater than start is not found. We want to add [20,30]. since upper bound of 20 isn't found we can add in the map.
       
       Now let's say we have to add [5,8] in map. Can we add ? yes as 8<=10
       */
       
      if(it==mp.end() || it->second>=end){     
            mp[end]=start;
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */