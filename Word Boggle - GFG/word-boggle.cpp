// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
    bool find(vector<vector<char> >&board,int i,int j,int idx,string word){
        if(i<0||j<0||i>=board.size()||j>=board[0].size()||board[i][j]!=word[idx])
           return false;
       
        if(idx==word.size()-1)
          return true;
          
        char temp=board[i][j];
        board[i][j]='#';
        
        bool up=find(board,i-1,j,idx+1,word);
        bool down=find(board,i+1,j,idx+1,word);
        bool left=find(board,i,j-1,idx+1,word);
        bool right=find(board,i,j+1,idx+1,word);
        bool upLeft=find(board,i-1,j-1,idx+1,word);
        bool downLeft=find(board,i+1,j-1,idx+1,word);
        bool upRight=find(board,i-1,j+1,idx+1,word);
        bool downRight=find(board,i+1,j+1,idx+1,word);
        
        board[i][j]=temp;
        if(up||down||left||right||upLeft||downLeft||upRight||downRight)
          return true;
        return false; 
        
    }
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    // Code here
	    vector<string>ans;
	    for(int i=0;i<dictionary.size();i++){
	        string word= dictionary[i];
	        for(int j=0;j<board.size();j++){
	            bool flag=false;
	            for(int k=0;k<board[0].size();k++){
	                if(board[j][k]==word[0] && find(board,j,k,0,word)){
	                  ans.push_back(word);
	                  flag=true;
	                  break;
	                }
	            }
	            if(flag)
	            break;
	        }
	    }
	    return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}
  // } Driver Code Ends