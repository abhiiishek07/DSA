// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool find(vector<vector<char>>&board,int i,int j,int idx,string &word){
        if(i<0||j<0||i>=board.size()||j>=board[0].size()||board[i][j]=='#'|| board[i][j]!=word[idx])
        return false;
        
        if(idx==word.length()-1){
         return true;
        }
        char temp=board[i][j];
        board[i][j]='#';
        
        bool d=find(board,i+1,j,idx+1,word);
        bool r=find(board,i,j+1,idx+1,word);
        bool u=find(board,i-1,j,idx+1,word);
        bool l=find(board,i,j-1,idx+1,word);
        
        board[i][j]=temp;
        
        return d||r||u||l;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(word[0]==board[i][j]){
                 if(find(board,i,j,0,word))
                  return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends