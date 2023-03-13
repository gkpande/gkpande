//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
  //recusrsive method
  int solve(vector<int>&cost ,int n){
      if(n==0){
          return cost[0];
      }
      if(n==1){
          return cost[1];
      }
      int ans=cost[n]+min(solve(cost,n-1),solve(cost,n-2));
      return ans;
  }
  //recursive + memorization
  int solve1(vector<int>&cost ,int n,vector<int>&dp){
      if(n==0){
          return cost[0];
      }
      if(n==1){
          return cost[1];
      }
      if(dp[n]!=-1){
          return dp[n];
      }
      
      dp[n]=cost[n]+min(solve1(cost,n-1,dp),solve1(cost,n-2,dp));
      return dp[n];
  }
    int minCostClimbingStairs(vector<int>&cost ,int N) {
        // to go at top N we require min step if came from N-1 or N-2.
        // int ans=min(solve(cost,N-1),solve(cost,N-2));
        // return ans;
        vector<int>dp(N+1,-1);
        dp[N] =min(solve1(cost,N-1,dp),solve1(cost,N-2,dp));
        return dp[N];
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>cost(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>cost[i];
        }

        Solution ob;
        cout<<ob.minCostClimbingStairs(cost,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends