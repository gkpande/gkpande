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
    long long int numberOfPaths(int m, int n){
       //recursive
    //   return solveRec(0,0,m,n);
    //rec+mem
    vector<vector<int>>dp(m,vector<int>(n,-1));
    return solveMem(0,0,m,n,dp);
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