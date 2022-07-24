class NumberContainers {
public:
    unordered_map<int,priority_queue<int,vector<int>,greater<int>>>mp1;
    unordered_map<int,int>mp2;
    NumberContainers() {
        mp1.clear();
        mp2.clear();
    }
    
    void change(int index, int number) {
        mp1[number].push(index);
        mp2[index]=number;
    }
    
    int find(int number) {
        if(mp1[number].size()==0)
            return -1;
        
        while(true){
            int idx=mp1[number].top();
            if(mp2[idx]==number)
               return idx;
            else
                mp1[number].pop();
            if(mp1[number].size()==0){
                mp1.erase(number);
                break;
            }
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */