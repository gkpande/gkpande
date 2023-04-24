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
    int maxGold(int n, int m, vector<vector<int>> M)
    {
       int fans=INT_MIN;
    //   for(int i=0;i<n;i++ ){
    //       int ans=solveRec(i,0,n,m,M);
    //       fans=max(fans,ans);
    //   }
    vector<vector<int>>dp(n,vector<int>(m,-1));
    for(int i=0;i<n;i++ ){
           int ans=solveMem(i,0,n,m,M,dp);
           
           fans=max(fans,ans);
       }
       return fans;
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