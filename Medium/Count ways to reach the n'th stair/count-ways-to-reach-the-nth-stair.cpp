//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int solveRec(int stair,int n){
        if(stair==n){
            return 1;
        }
        if(stair>n){
            return 0;
        }
        return solveRec(stair+1,n)+solveRec(stair+2,n);
    }
    int solveMem(int stair,int n,vector<int>&dp){
        if(stair==n){
            return 1;
        }
        if(stair>n){
            return 0;
        }
        if(dp[stair]!=-1){
            return dp[stair];
        }
        dp[stair]=(solveMem(stair+1,n,dp)+solveMem(stair+2,n,dp))%1000000007;
        return dp[stair];
    }
    int countWays(int n)
    {
        // return solveRec(0,n);
        //add memorization
        vector<int>dp(n,-1);
        return solveMem(0,n,dp);
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends