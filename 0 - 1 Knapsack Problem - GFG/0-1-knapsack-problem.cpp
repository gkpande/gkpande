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
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       //recursive
    //   return solveRec(W,wt,val,n-1);
    //recursive+mem
    vector<vector<int>>dp(n,vector<int>(W+1,-1));
    return solveMem(W,wt,val,n-1,dp);
       
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