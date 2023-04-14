//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int addMinChar(string str){    
        //code here
        int cnt=0,s=0,e=str.size()-1;
        while(s<=e){
            if(str[s]==str[e]){
                s++;
                e--;
            }
            else {
                s=0;
                cnt++;
                e=str.size()-cnt-1;
            }
        }
        return cnt;
        
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends