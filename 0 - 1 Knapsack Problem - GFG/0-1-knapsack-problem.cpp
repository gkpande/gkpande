//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    //recursive
    int solve(int W, int wt[], int val[], int n){
        if(n==0){
            if(wt[n]<=W){
                return val[n];
            }
            else{
                return 0;
            }
        }
        int incl=0;
        int excl=0;
        if(wt[n]<=W){
            incl=val[n]+solve(W-wt[n],wt,val,n-1);
        }
        excl=0+solve(W,wt,val,n-1);
        return max(incl,excl);
    }
    //recursive+memorization.
    int solveMem(int W, int wt[], int val[], int n,vector<vector<int>>&dp){
        if(n==0){
            if(wt[n]<=W){
                return val[n];
            }
            else{
                return 0;
            }
        }
        
        if(dp[n][W]!=-1){
            return dp[n][W];
        }
        
        int incl=0;
        int excl=0;
        if(wt[n]<=W){
            incl=val[n]+solveMem(W-wt[n],wt,val,n-1,dp);
        }
        excl=0+solveMem(W,wt,val,n-1,dp);
        dp[n][W]=max(incl,excl);
        return dp[n][W];
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
    //   return solve(W,wt,val,n-1);
    
    vector<vector<int>>dp(n,vector<int>(W+1,-1));
    return solveMem(W,wt,val,n-1,dp);
    
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends