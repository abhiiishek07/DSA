class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size()==1){         // for only one size
          return "";
        }
        
        bool flag=true;
        for(int i=0;i<palindrome.size()/2;i++){
            if(palindrome[i]!='a'){
                flag=false;             // checks whether we have changed... if there is only a's.
                palindrome[i]='a';
                return palindrome;
            }
        }
        if(flag){                         // if only a's in given string change last character
            palindrome[palindrome.size()-1]='b'; 
        }
        return palindrome;
        
    }
};