class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for(int i=num/2;i<=num;i++){
            string str= to_string(i);
            string temp=str;
            reverse(temp.begin(),temp.end());
            if(stoi(str)+stoi(temp)==num)
                return true;
        }
        return false;
    }
};