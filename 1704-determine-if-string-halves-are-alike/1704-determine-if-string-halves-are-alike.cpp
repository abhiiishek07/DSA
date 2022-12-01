class Solution {
public:
    bool isVowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U';
    }
    bool halvesAreAlike(string s) {
        int cnt1=0,cnt2=0;
        for(int i=0;i<s.size();i++){
            if(i<s.size()/2 && isVowel(s[i]))
                cnt1++;
            else if(i>=s.size()/2 && isVowel(s[i]))
                cnt2++;
        }
        return cnt1==cnt2;
    }
};