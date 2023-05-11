//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int solveRec(int n,int k){
        //base case
        if(k==0||k==1){
            return k;
        }
        if(n==1){
            return k;
        }
        int mini=INT_MAX;
        int res;
        for(int i=1;i<=k;i++){
            res=max(solveRec(n-1,i-1),solveRec(n,k-i));
            mini=min(res,mini);
        }
        return mini+1;
    }
    int solveMem(int n,int k,vector<vector<int>>&dp){
        //base case
        if(k==0||k==1){
            return k;
        }
        if(n==1){
            return k;
        }
        if(dp[n][k]!=-1){
            return dp[n][k];
        }
        int mini=INT_MAX;
        int res;
        for(int i=1;i<=k;i++){
            res=max(solveMem(n-1,i-1,dp),solveMem(n,k-i,dp));
            mini=min(res,mini);
        }
        dp[n][k]=mini+1;
        return dp[n][k];
    }
    int eggDrop(int n, int k) 
    {
        // return solveRec(n,k);
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return solveMem(n,k,dp);
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
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends