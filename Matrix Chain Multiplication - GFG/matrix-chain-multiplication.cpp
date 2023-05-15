//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int solveRecMcm(int arr[],int i,int j){
    if(i==j){
        return 0;// if one matrix than no multiplication required.
    }
    int minMul=INT_MAX;
    for(int k=i;k<j;k++){
        int ans=solveRecMcm(arr,i,k) + solveRecMcm(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        minMul=min(minMul,ans);
    }
    return minMul;
}
int solveRecMcmMem(int arr[],int i,int j,vector<vector<int>>&dp){
    if(i==j){
        return 0;// if one matrix than no multiplication required.
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int minMul=INT_MAX;
    for(int k=i;k<j;k++){
        int ans=solveRecMcmMem(arr,i,k,dp) + solveRecMcmMem(arr,k+1,j,dp)+arr[i-1]*arr[k]*arr[j];
        minMul=min(minMul,ans);
    }
    dp[i][j]=minMul;
    return dp[i][j];
}
int solveRecMcmTab(int arr[],int N){
    vector<vector<int>>dp(N,vector<int>(N,0));
    for(int i=N-1;i>=1;i--){
        for(int j=i+1;j<N;j++){
            int minMul=INT_MAX;
            for(int k=i;k<j;k++){
                int ans=dp[i][k] + dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
                minMul=min(ans,minMul);
            }
            dp[i][j]=minMul;
        }
    }
    return dp[1][N-1];
}
    int matrixMultiplication(int N, int arr[])
    {
        // return solveRecMcm(arr,1,N-1);
        // vector<vector<int>>dp(N,vector<int>(N,-1));
        // return solveRecMcmMem(arr,1,N-1,dp);
        return solveRecMcmTab(arr,N);
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
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends