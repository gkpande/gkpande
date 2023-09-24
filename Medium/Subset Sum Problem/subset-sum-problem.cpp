//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
bool solveRec(vector<int>arr, int sum,int i,int n){
    if(sum==0){
        return true;
    }
    if(i>=n){
        return false;
    }
    bool take=false;
    if(arr[i]<=sum){
        take=solveRec(arr,sum-arr[i],i+1,n);
    }
    bool notTake=solveRec(arr,sum,i+1,n);
    return (take||notTake);
}
bool solveMem(vector<int>arr, int sum,int i,int n,vector<vector<int>>&dp){
    if(sum==0){
        return true;
    }
    if(i>=n){
        return false;
    }
    if(dp[i][sum]!=-1){
        return dp[i][sum];
    }
    bool take=false;
    if(arr[i]<=sum){
        take=solveMem(arr,sum-arr[i],i+1,n,dp);
    }
    bool notTake=solveMem(arr,sum,i+1,n,dp);
    dp[i][sum]= (take||notTake);
    return dp[i][sum];
}
    bool isSubsetSum(vector<int>arr, int sum){
        //solveRec
        int n=arr.size();
        // return solveRec(arr,sum,0,n);
        //add memorization
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solveMem(arr,sum,0,n,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends