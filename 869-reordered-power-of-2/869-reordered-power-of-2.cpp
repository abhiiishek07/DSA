class Solution {
public:
    void frequency(int num,unordered_map<int,int>&mp){
        while(num>0){
            mp[num%10]++;
            num/=10;
        }
        return;
    }
    bool reorderedPowerOf2(int n) {
        unordered_map<int,int>digitFreq;
        frequency(n,digitFreq);
        for(int i=0;i<31;i++){
            int powerOfTwo=(int)pow(2,i);
            unordered_map<int,int>powerOfTwoFreq;
            frequency(powerOfTwo,powerOfTwoFreq);
            if(digitFreq==powerOfTwoFreq)
                return true;
        }
        return false;
    }
};