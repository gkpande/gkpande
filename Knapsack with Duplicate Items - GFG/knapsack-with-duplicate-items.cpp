//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int solveRec(int N, int W, int val[], int wt[],int index){
    if(W==0){
        return 0;
    }
    if(index>=N){
        return 0;
    }
    int take=INT_MIN;
    if(wt[index]<=W){
        take=val[index]+solveRec(N,W-wt[index],val,wt,index);
    }
    int nTake=0+solveRec(N,W,val,wt,index+1);
    return max(take,nTake);
}
int solveMem(int N, int W, int val[], int wt[],int index,vector<vector<int>>&dp){
    if(W==0){
        return 0;
    }
    if(index>=N){
        return 0;
    }
    if(dp[index][W]!=-1){
        return dp[index][W];
    }
    int take=INT_MIN;
    if(wt[index]<=W){
        take=val[index]+solveMem(N,W-wt[index],val,wt,index,dp);
    }
    int nTake=0+solveMem(N,W,val,wt,index+1,dp);
    dp[index][W]= max(take,nTake);
    return dp[index][W];
}

    int knapSack(int N, int W, int val[], int wt[])
    {
        //------recursive
        // return solveRec(N,W,val,wt,0);
        //-----rec+mem
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
        return solveMem(N,W,val,wt,0,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends