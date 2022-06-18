class Solution {
public:
    bool isVowel(char ch){
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }
    int maxVowels(string s, int k) {
        int i=0,j=0;
        int ans=0,cnt=0;
        while(j<s.length()){
          if(isVowel(s[j]))        
              cnt++;
            if(j-i+1==k){                 // window size of K hit
                 ans=max(ans,cnt);   
                if(isVowel(s[i]))        // checking if first elem of window is vowel
                    cnt--;
                i++;                     
            }
            j++;
        }
        return ans;
    }
};