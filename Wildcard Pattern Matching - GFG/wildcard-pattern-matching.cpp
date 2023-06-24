//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
int solveRec(string p,string s,int i,int j){
    if(i<0 && j<0){
        return 1;
    }
    if(i<0 && j>=0){
        return 0;
    }
    if(i>=0 && j<0){
        for(int k=0;k<=i;k++){
            if(p[k]!='*'){
                return 0;
            }
        }
        return 1;
    }
    if(p[i]==s[j] || p[i]=='?'){
        return solveRec(p,s,i-1,j-1);
    }
    else if(p[i]=='*'){
        return solveRec(p,s,i-1,j) || solveRec(p,s,i,j-1);
    }
    else{
        return 0;
    }
}
int solveMem(string p,string s,int i,int j,vector<vector<int>>&dp){
    if(i<0 && j<0){
        return 1;
    }
    if(i<0 && j>=0){
        return 0;
    }
    if(i>=0 && j<0){
        for(int k=0;k<=i;k++){
            if(p[k]!='*'){
                return 0;
            }
        }
        return 1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(p[i]==s[j] || p[i]=='?'){
        return dp[i][j]= solveMem(p,s,i-1,j-1,dp);
    }
    else if(p[i]=='*'){
        return dp[i][j]=solveMem(p,s,i-1,j,dp) || solveMem(p,s,i,j-1,dp);
    }
    else{
        return 0;
    }
}

    int wildCard(string pattern,string str)
    {
        int m=pattern.length();
        int n=str.length();
        // return solveRec(pattern,str,m-1,n-1);
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solveMem(pattern,str,m-1,n-1,dp);
        
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends