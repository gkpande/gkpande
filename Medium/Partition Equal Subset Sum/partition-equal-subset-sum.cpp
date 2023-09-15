//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solveRec(int n,int arr[],int sum){
        if(sum==0){
            return 1;
        }
        if(sum!=0 && n==0){
            return 0;
        }
        if(arr[n-1]>sum){
            return solveRec(n-1,arr,sum);
        }
        return solveRec(n-1,arr,sum-arr[n-1])||solveRec(n-1,arr,sum);
    }
    int solveMem(int n,int arr[],int sum,vector<vector<int>>&dp){
        if(sum==0){
            return 1;
        }
        if(sum!=0 && n==0){
            return 0;
        }
        if(dp[sum][n]!=-1){
            return dp[sum][n];
        }
        if(arr[n-1]>sum){
            return solveRec(n-1,arr,sum);
        }
        dp[sum][n]= solveMem(n-1,arr,sum-arr[n-1],dp)||solveMem(n-1,arr,sum,dp);
        return dp[sum][n];
    }
    int solveTab(int n,int arr[],int sum){
        vector<vector<int>>dp(sum,vector<int>(n+1,0));
        for(int i=0;i<=n;i++){
            dp[0][i]=1;
        }
        for(int i=1;i<=sum;i++){
            for(int j=1;j<=n;j++){
                if(arr[j-1]>i){
                    dp[i][j]=dp[i][j-1];
                }else{
                    dp[i][j]= dp[i-arr[j-1]][j-1]||dp[i][j-1];
                }
                
            }
        }
        
        
        return dp[sum][n];
    }
    int spaceOp(int n,int arr[],int sum){
        vector<int>next(sum+1,0);
        next[0]=1;
        
        vector<int>curr(sum+1,0);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=sum;j++){
                int incl=0;
                if(j-arr[i]>=0){
                    incl=next[j-arr[i]];
                }
                int excl=next[j];
                curr[j]=incl||excl;
            }
            next=curr;
        }
        return next[sum];
    }
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++){
            sum=sum+arr[i];
        }
        if(sum%2==1){
            return 0;
        }
        // return solveRec(N,arr,sum/2);
        // vector<vector<int>>dp(sum/2+1,vector<int>(N+1,-1));
        // return solveMem(N,arr,sum/2,dp);
        // return solveTab(N,arr,sum/2);
        return spaceOp(N,arr,sum/2);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends