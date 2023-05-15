//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int solveRec(int i,int j,vector<vector<int>>&Matrix,int N){
    if(i==N-1){
        return Matrix[i][j];
    }
    int ans1,ans2,ans3;
    //lower digonal
    if(i+1<N && j-1>=0){
        ans1=Matrix[i][j]+solveRec(i+1,j-1,Matrix,N);
    }
    //lower
    if(i+1<N){
        ans2=Matrix[i][j]+solveRec(i+1,j,Matrix,N);
    }
    //lower right diagnola
    if(i+1<N && j+1<N){
        ans3=Matrix[i][j]+solveRec(i+1,j+1,Matrix,N);
    }
    return max(ans1,max(ans2,ans3));
}
int solveMem(int i,int j,vector<vector<int>>&Matrix,int N,vector<vector<int>>&dp){
    if(i==N-1){
        return Matrix[i][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans1=0,ans2=0,ans3=0;
    //lower digonal
    if(i+1<N && j-1>=0){
        ans1=Matrix[i][j]+solveMem(i+1,j-1,Matrix,N,dp);
    }
    //lower
    if(i+1<N){
        ans2=Matrix[i][j]+solveMem(i+1,j,Matrix,N,dp);
    }
    //lower right diagnola
    if(i+1<N && j+1<N){
        ans3=Matrix[i][j]+solveMem(i+1,j+1,Matrix,N,dp);
    }
    dp[i][j]=max(ans1,max(ans2,ans3));
    return dp[i][j];
}
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int maxPath=INT_MIN;
        // for(int i=0;i<N;i++){
        //     int ans=solveRec(0,i,Matrix,N);
        //     maxPath=max(maxPath,ans);
        // }
        vector<vector<int>>dp(N,vector<int>(N,-1));
        for(int i=0;i<N;i++){
            int ans=solveMem(0,i,Matrix,N,dp);
            maxPath=max(maxPath,ans);
        }
        return maxPath;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends