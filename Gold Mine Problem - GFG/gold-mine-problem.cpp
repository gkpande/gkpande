//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int solveRec(int start,int end,int n,int m,vector<vector<int>> &M){
    if(start>=n  || start<0 || end>=m || end<0 ){
        return 0;
    }
    int ans1=M[start][end]+solveRec(start-1,end+1,n,m,M);
    int ans2=M[start][end]+solveRec(start,end+1,n,m,M);
    int ans3=M[start][end]+solveRec(start+1,end+1,n,m,M);
    return max(ans1,max(ans2,ans3));
}
int solveMem(int start,int end,int n,int m,vector<vector<int>> &M,vector<vector<int>>&dp){
    if(start>=n  || start<0 || end>=m || end<0 ){
        return 0;
    }
    if(dp[start][end]!=-1){
        return dp[start][end];
    }
    int ans1=M[start][end]+solveMem(start-1,end+1,n,m,M,dp);
    int ans2=M[start][end]+solveMem(start,end+1,n,m,M,dp);
    int ans3=M[start][end]+solveMem(start+1,end+1,n,m,M,dp);
    dp[start][end]= max(ans1,max(ans2,ans3));
    return dp[start][end];
}
int solveTab(int n,int m,vector<vector<int>> &M){
    vector<vector<int>>dp(n,vector<int>(m,-1));
    
    for(int j=m-1;j>=0;j--){
        for(int i=0;i<n;i++){
           
                int ans1=(j==m-1 || i==0)?0:dp[i-1][j+1];
            

            int ans2=(j==m-1)?0:dp[i][j+1];
           
               int ans3=(i==n-1 || j==m-1)?0:dp[i+1][j+1];
           
            dp[i][j]=M[i][j]+max(ans1,max(ans2,ans3));
        }
    }
    int fans=INT_MIN;
    for(int i=0;i<n;i++){
        fans=max(fans,dp[i][0]);
    }
    return fans;
    
}
int solveSo(int n,int m,vector<vector<int>> &M){
    vector<int>curr(n,0);
    vector<int>prev(n,0);
    
    for(int j=m-1;j>=0;j--){
        for(int i=0;i<n;i++){
           //lower right diagonal.
            int ans1=(j==m-1 || i==0)?0:prev[i-1];
            

            int ans2=(j==m-1)?0:prev[i];
           
               int ans3=(i==n-1 || j==m-1)?0:prev[i+1];
           
            curr[i]=M[i][j]+max(ans1,max(ans2,ans3));
        }
        prev=curr;
    }
    int fans=INT_MIN;
    for(int i=0;i<n;i++){
        fans=max(fans,prev[i]);
    }
    return fans;
    
}
    int maxGold(int n, int m, vector<vector<int>> M)
    {
       int fans=INT_MIN;
    //   for(int i=0;i<n;i++ ){
    //       int ans=solveRec(i,0,n,m,M);
    //       fans=max(fans,ans);
    //   }
    //--------------------------//
    // vector<vector<int>>dp(n,vector<int>(m,-1));
    // for(int i=0;i<n;i++ ){
    //       int ans=solveMem(i,0,n,m,M,dp);
           
    //       fans=max(fans,ans);
    //   }
    //---------------tabulation---------------
    return solveTab(n,m,M);
    //----------space optimization
    return solveSo(n,m,M);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends