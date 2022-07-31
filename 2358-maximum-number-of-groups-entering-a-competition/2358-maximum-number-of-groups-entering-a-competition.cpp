class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int size=grades.size();
        int parti=1,cnt=0;
        while(size>0){
            if(size>=parti){
                size-=parti;
                parti+=1;
                cnt++;
            }
            else
                break;
        }
        return cnt;
    }
};