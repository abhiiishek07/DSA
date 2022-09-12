class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int score=0;
        int i=0,j=tokens.size()-1;
        while(i<=j){
            if(score==0 && power<tokens[i] || i==j && power<tokens[i])
                break;
            else if(power>=tokens[i]){
                score++;
                power-=tokens[i];
                i++;
            }
            else if(power<tokens[i]){
                power+=tokens[j];
                j--;
                score--;
            }
        }
        return score;
    }
};