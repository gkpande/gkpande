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
int solveTab(int N, int W, int val[], int wt[]){
    vector<vector<int>>dp(N,vector<int>(W+1,0));
    for(int w=0;w<=W;w++){
        dp[N-1][w]= int(w/wt[N-1])* val[N-1];
    }
    for(int i=N-2;i>=0;i--){
        for(int w=0;w<=W;w++ ){
            int take =0;
            if(wt[i]<=w){
                take=val[i]+dp[i][w-wt[i]];
            }
            int nTake=0+dp[i+1][w];
            dp[i][w]= max(take,nTake);
        }
    }
    return dp[0][W];
    
}


    int knapSack(int N, int W, int val[], int wt[])
    {
        //------recursive
        // return solveRec(N,W,val,wt,0);
        //-----rec+mem
        // vector<vector<int>>dp(N,vector<int>(W+1,-1));
        // return solveMem(N,W,val,wt,0,dp);
        //-----tabulation
        return solveTab(N,W,val,wt);
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