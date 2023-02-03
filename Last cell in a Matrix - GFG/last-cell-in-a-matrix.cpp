//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix, int R, int C){
        //code here
        int i=0,j=0,x=0,y=0;
        char dir='r';
        while(i>=0 && j>=0 && i<R && j<C){
             x=i;
             y=j;
            if(matrix[i][j]==0){
                if(dir=='r') j++;
                else if(dir=='d') i++;
                else if(dir=='l') j--;
                else if(dir=='u') i--;
            }
            else{
                matrix[i][j]=0;
                if(dir=='r'){
                    dir='d';
                    i++;
                }
                else if(dir=='l'){
                    dir='u';
                    i--;
                }
                else if(dir=='u'){
                    dir='r';
                    j++;
                }
                else if(dir=='d'){
                    dir='l';
                    j--;
                }
            }
        }
        return {x,y};
        
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends