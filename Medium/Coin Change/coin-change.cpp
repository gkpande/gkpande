//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  long long int solveRec(int coins[],int n,int s, int i){
      if(s==0){
          return 1;
      }
      if(i>=n){
          return 0;
      }
      int take=0,notTake=0;
      if(coins[i]<=s){
          take =take+solveRec(coins,n,s-coins[i],i);    
      }
      notTake =notTake+solveRec(coins,n,s,i+1);
      return take+notTake;
  }
  long long int solveMem(int coins[],int n,int s, int i,vector<vector<int>>&dp){
      if(s==0){
          return 1;
      }
      if(i>=n){
          return 0;
      }
      if(dp[i][s]!=-1){
          return dp[i][s];
      }
      int take=0,notTake=0;
      if(coins[i]<=s){
          take =take+solveMem(coins,n,s-coins[i],i,dp);    
      }
      notTake =notTake+solveMem(coins,n,s,i+1,dp);
      dp[i][s]=take+notTake;
      return dp[i][s];
  }
  long long int solveTab(int coins[],int n,int s){
      vector<vector<long long int>>dp(n+1,vector<long long int>(s+1,0));
      for(int i=0;i<=n;i++){
          dp[i][0]=1;
      }
      for(int i=n-1;i>=0;i--){
          
          for(int j=1;j<=s;j++){
              long long int take=0,notTake=0;
              if(coins[i]<=j){
                    take =dp[i][j-coins[i]];    
                }
            notTake =dp[i+1][j];
            dp[i][j]=take+notTake;
          }
      }
      
      
      
      
      return dp[0][s];
  }
    long long int count(int coins[], int N, int sum) {

        // return solveRec(coins,N,sum,0);
        // vector<vector<int>>dp(N+1,vector<int>(sum+1,-1));
        // return solveMem(coins,N,sum,0,dp);
        return solveTab(coins,N,sum);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends