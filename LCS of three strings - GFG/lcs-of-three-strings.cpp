//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends

int solveRec(string A, string B, string C,int i,int j,int k,int n1,int n2,int n3){
    if(i==n1 || j==n2 || k==n3){
        return 0;
    }
    int ans=0;
    if(A[i]==B[j] && B[j]==C[k]){
        ans=1+solveRec(A,B,C,i+1,j+1,k+1,n1,n2,n3);
    }
    else{
        ans=max(solveRec(A,B,C,i+1,j,k,n1,n2,n3),max(solveRec(A,B,C,i,j+1,k,n1,n2,n3),solveRec(A,B,C,i,j,k+1,n1,n2,n3)));
    }
    return ans;
}
int solveMem(string A, string B, string C,int i,int j,int k,int n1,int n2,int n3,vector<vector<vector<int>>>&dp){
    if(i==n1 || j==n2 || k==n3){
        return 0;
    }
    if(dp[i][j][k]!=-1){
        return dp[i][j][k];
    }
    int ans=0;
    if(A[i]==B[j] && B[j]==C[k]){
        ans=1+solveMem(A,B,C,i+1,j+1,k+1,n1,n2,n3,dp);
    }
    else{
        ans=max(solveMem(A,B,C,i+1,j,k,n1,n2,n3,dp),max(solveMem(A,B,C,i,j+1,k,n1,n2,n3,dp),solveMem(A,B,C,i,j,k+1,n1,n2,n3,dp)));
    }
    dp[i][j][k]=ans;
    return dp[i][j][k];
}
int solveTab(string A, string B, string C,int n1,int n2,int n3){
    vector<vector<vector<int>>>dp(n1+1,vector<vector<int>>(n2+1,vector<int>(n3+1,0)));
    for(int i=n1-1;i>=0;i--){
        for(int j=n2-1;j>=0;j--){
            for(int k=n3-1;k>=0;k--){
              if(A[i]==B[j] && B[j]==C[k]){
                    dp[i][j][k]=1+dp[i+1][j+1][k+1];
              }
             else{
                    dp[i][j][k]=max(dp[i+1][j][k],max(dp[i][j+1][k],dp[i][j][k+1]));
             }
            }
        }
    }
    return dp[0][0][0];
}
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // return solveRec(A,B,C,0,0,0,n1,n2,n3);
    // vector<vector<vector<int>>>dp(n1,vector<vector<int>>(n2,vector<int>(n3,-1)));
    // return solveMem(A,B,C,0,0,0,n1,n2,n3,dp);
    return solveTab(A,B,C,n1,n2,n3);
}