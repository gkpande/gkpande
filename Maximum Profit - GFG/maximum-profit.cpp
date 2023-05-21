//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int solveRec(int i,int t,int L,int N,int A[]){  // L-limit,l=2*k
      if(i==N){
          return 0;
      }
      if(t==L){
          return 0;
      }
      int profit=0;
      if(t%2==0){
          //buy
          int buy= -A[i]+solveRec(i+1,t+1,L,N,A);
          int skip=0+solveRec(i+1,t,L,N,A);
          profit=max(buy,skip);
      }
      else{
          //sell
          int sell=A[i]+solveRec(i+1,t+1,L,N,A);
          int skip=0+solveRec(i+1,t,L,N,A);
          profit=max(sell,skip);
      }
      return profit;
  }
  int solveMem(int i,int t,int L,int N,int A[], vector<vector<int>>&dp){  // L-limit,l=2*k
      if(i==N){
          return 0;
      }
      if(t==L){
          return 0;
      }
      if(dp[i][t]!=-1){
          return dp[i][t];
      }
      int profit=0;
      if(t%2==0){
          //buy
          int buy= -A[i]+solveMem(i+1,t+1,L,N,A,dp);
          int skip=0+solveMem(i+1,t,L,N,A,dp);
          profit=max(buy,skip);
      }
      else{
          //sell
          int sell=A[i]+solveMem(i+1,t+1,L,N,A,dp);
          int skip=0+solveMem(i+1,t,L,N,A,dp);
          profit=max(sell,skip);
      }
      dp[i][t]=profit;
      return dp[i][t];
  }
  int solveTab(int K,int N,int A[]){  // L-limit,l=2*k
      vector<vector<int>>dp(N+1,vector<int>(2*K+1,0));
      for(int i=N-1;i>=0;i--){
          for(int t=2*K-1;t>=0;t--){
                int profit=0;
                if(t%2==0){
                //buy
                    int buy= -A[i]+dp[i+1][t+1];
                    int skip=0+dp[i+1][t];
                    profit=max(buy,skip);
                }
                else{
                    //sell
                    int sell=A[i]+dp[i+1][t+1];
                    int skip=0+dp[i+1][t];
                    profit=max(sell,skip);
                }
                dp[i][t]=profit; 
            }
        }
      
      return dp[0][0];
  }
    int maxProfit(int K, int N, int A[]) {
        //can reuse the code most 2 transaction
        // return solveRec(0,0,2*K,N,A);
        //add memorization
        // vector<vector<int>>dp(N,vector<int>(2*K,-1));
        // return solveMem(0,0,2*K,N,A,dp);
        //tabulation
        return solveTab(K,N,A);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends