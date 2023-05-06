//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  int solveRec(int i,int j,int m,int n){
      //base case
      if(i==m-1 && j==n-1){
          return 1;
      }
      int d=0,r=0;
      if(i+1<m){
          d=solveRec(i+1,j,m,n);
      }
      if(j+1<n){
          r=solveRec(i,j+1,m,n);
      }
      return d+r;
  }
  int solveMem(int i,int j,int m,int n,vector<vector<int>>&dp){
      //base case
      if(i==m-1 && j==n-1){
          return 1;
      }
      if(dp[i][j]!=-1){
          return dp[i][j];
      }
      int d=0,r=0;
      if(i+1<m){
          d=solveMem(i+1,j,m,n,dp);
      }
      if(j+1<n){
          r=solveMem(i,j+1,m,n,dp);
      }
      dp[i][j]=(d+r)%1000000007;
      return dp[i][j];
  }
  int solveTab(int i,int j,int m,int n){
      vector<vector<int>>dp(m+1,vector<int>(n+1,0));
      for(int i=0;i<n;i++){
          dp[m-1][i]=1;
      }
      for(int i=m-2;i>=0;i--){
          for(int j=n-1;j>=0;j--){
              dp[i][j]=(dp[i+1][j]+dp[i][j+1])%1000000007;
          }
      }
      return dp[0][0];
  }
  int solveSo(int i,int j,int m,int n){
      vector<int>prev(n,1);
      vector<int>curr(n,0);
      for(int i=m-2;i>=0;i--){
          curr[n-1]=1;
          for(int j=n-2;j>=0;j--){
              curr[j]=(prev[j]+curr[j+1])%1000000007;
          }
          prev=curr;
      }
      return prev[0];
  }
    long long int numberOfPaths(int m, int n){
       //recursive
    //   return solveRec(0,0,m,n);
    //rec+mem
    // vector<vector<int>>dp(m,vector<int>(n,-1));
    // return solveMem(0,0,m,n,dp);
    // return solveTab(0,0,m,n);
    //space optimization
    return solveSo(0,0,m,n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}

// } Driver Code Ends