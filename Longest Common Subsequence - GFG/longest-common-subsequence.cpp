//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int solveRec(int x,int y,string s1,string s2,int i,int j){
        if(i==x){
            return 0;
        }
        if(j==y){
            return 0;
        }
        int ans=0;
        if(s1[i]==s2[j]){
            ans=1+solveRec(x,y,s1,s2,i+1,j+1);
           
        }
        else{
            ans= max(solveRec(x,y,s1,s2,i+1,j),solveRec(x,y,s1,s2,i,j+1));
        }
         return ans;
    }
    int solveMem(int x,int y,string s1,string s2,int i,int j,vector<vector<int>>&dp){
        if(i==x){
            return 0;
        }
        if(j==y){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(s1[i]==s2[j]){
            ans=1+solveRec(x,y,s1,s2,i+1,j+1);
           
        }
        else{
            ans= max(solveMem(x,y,s1,s2,i+1,j,dp),solveMem(x,y,s1,s2,i,j+1,dp));
        }
         return dp[i][j]=ans;
    }
    int solveTab(int x,int y,string s1,string s2){
        vector<vector<int>>dp(x+1,vector<int>(y+1,0));
        for(int i=x-1;i>=0;i--){
            for(int j=y-1;j>=0;j--){
                if(s1[i]==s2[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                }
                else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
    int lcs(int x, int y, string s1, string s2)
    {
        // return solveRec(x,y,s1,s2,0,0);
        // vector<vector<int>>dp(x,vector<int>(y,-1));
        // return solveMem(x,y,s1,s2,0,0,dp);
        return solveTab(x,y,s1,s2);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends