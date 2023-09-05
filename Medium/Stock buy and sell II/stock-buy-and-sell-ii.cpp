//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
  int solveRec(int n,vector<int>&prices,int buy,int i){
      if(i>=n){
          //no profit
          return 0;
      }
      int take=0;
      int notTake;
      if(buy==1){
          take=-prices[i]+solveRec(n,prices,0,i+1);
          notTake=0+solveRec(n,prices,1,i+1);
        //   return  max(take,notTake);
      }
      else{
          take=prices[i]+solveRec(n,prices,1,i+1);
          notTake=0+solveRec(n,prices,0,i+1);
          
      }
      return  max(take,notTake);
      
  }
  int solveMem(int n,vector<int>&prices,int buy,int i,vector<vector<int>>&dp){
      if(i>=n){
          //no profit
          return 0;
      }
      if(dp[buy][i]!=-1){
          return  dp[buy][i];
      }
      int take=0;
      int notTake;
      if(buy==1){
          take=-prices[i]+solveMem(n,prices,0,i+1,dp);
          notTake=0+solveMem(n,prices,1,i+1,dp);
        //   return  max(take,notTake);
      }
      else{
          take=prices[i]+solveMem(n,prices,1,i+1,dp);
          notTake=0+solveMem(n,prices,0,i+1,dp);
          
      }
      dp[buy][i]=max(take,notTake);
      return  dp[buy][i];
      
  }
    int stockBuyAndSell(int n, vector<int> &prices) {
        // each day we have 2 choice either buy or sell
        //if buy==1 that means we will buy if buy==0 means sell
        // return solveRec(n,prices,1,0);
        vector<vector<int>>dp(2,vector<int>(n,-1));
        return solveMem(n,prices,1,0,dp);
        // return solveRec(n,prices,1,0);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends