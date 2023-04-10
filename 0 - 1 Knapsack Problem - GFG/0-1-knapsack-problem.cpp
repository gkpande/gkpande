//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solveRec(int capacity, int wt[], int val[], int index){
        if(index==0){
            if(wt[index]<=capacity){
                return val[index];
            }
            else{
                return 0;
            }
        }
        int include=0;
        if(wt[index]<=capacity){
            include=val[index]+solveRec(capacity-wt[index],wt,val,index-1);
        }
        int exlude=0+solveRec(capacity,wt,val,index-1);
        return max(include,exlude);
    }
    int solveMem(int capacity, int wt[], int val[], int index,vector<vector<int>>&dp){
        if(index==0){
            if(wt[index]<=capacity){
                return val[index];
            }
            else{
                return 0;
            }
        }
        if(dp[index][capacity]!=-1){
            return dp[index][capacity];
        }
        int include=0;
        if(wt[index]<=capacity){
            include=val[index]+solveMem(capacity-wt[index],wt,val,index-1,dp);
        }
        int exlude=0+solveMem(capacity,wt,val,index-1,dp);
        dp[index][capacity]= max(include,exlude);
        return dp[index][capacity];
    }
    int solveTab(int capacity, int wt[], int val[], int n){
        vector<vector<int>>dp(n,vector<int>(capacity+1,0));
        //if index=0
        for(int w=wt[0];w<=capacity;w++){
            if(wt[0]<=capacity){
                dp[0][w]=val[0];
            }
            else{
                dp[0][w]=0;
            }
        }
        for(int index=1;index<n;index++ ){
            for(int w=0;w<=capacity;w++){
                int include=0;
                if(wt[index]<=w){
                    include=val[index]+dp[index-1][w-wt[index]];
                }
                int exlude=0+dp[index-1][w];
                dp[index][w]= max(include,exlude);  
            }
        }
        return dp[n-1][capacity];
    }
    int solveSo(int capacity, int wt[], int val[], int n){
        vector<vector<int>>dp(n,vector<int>(capacity+1,0));
        vector<int>prev(capacity+1,0);
        vector<int>curr(capacity+1,0);
        //if index=0
        for(int w=wt[0];w<=capacity;w++){
            if(wt[0]<=capacity){
                prev[w]=val[0];
            }
            else{
                prev[w]=0;
            }
        }
        for(int index=1;index<n;index++ ){
            for(int w=0;w<=capacity;w++){
                int include=0;
                if(wt[index]<=w){
                    include=val[index]+prev[w-wt[index]];
                }
                int exlude=0+prev[w];
                curr[w]= max(include,exlude);  
            }
            prev=curr;
        }
        return prev[capacity];
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       //recursive
    //   return solveRec(W,wt,val,n-1);
    //recursive+mem
    // vector<vector<int>>dp(n,vector<int>(W+1,-1));
    // return solveMem(W,wt,val,n-1,dp);
    //tabulation
    // return solveTab(W,wt,val,n);
    return solveSo(W,wt,val,n);
       
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