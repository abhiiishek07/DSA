// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

vector<string>  spaceString(char str[]);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        char str[10000];
        cin>>str;
        vector<string> vec = spaceString(str);
        for(string s: vec){
            cout<<s<<"$";
        }
        cout<<endl;
    }

}
// } Driver Code Ends


/*You have to complete this function*/
void solve(char str[],string temp,int i,vector<string>&ans)
{
   if(strlen(str) == i)
   {
       ans.push_back(temp);
       return;
   }
   solve(str,temp+str[i],i+1,ans);
   
   solve(str,temp+" "+str[i],i+1,ans);
   
}
vector<string>  spaceString(char str[])
{
  vector<string>ans;
  string temp="";
  solve(str,temp+str[0],1,ans);
  return ans;
}



 