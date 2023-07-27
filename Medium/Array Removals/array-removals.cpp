//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int solveRec(vector<int>& arr, int k,int i,int j){
        if(i==j){
            return 0;
        }
        if(arr[j]-arr[i]<=k){
            return 0;
        }
        return 1+min(solveRec(arr,k,i+1,j),solveRec(arr,k,i,j-1));
    }
    int solveMem(vector<int>& arr, int k,int i,int j,vector<vector<int>>&dp){
        if(i==j){
            return 0;
        }
        if(arr[j]-arr[i]<=k){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        dp[i][j]=1+min(solveMem(arr,k,i+1,j,dp),solveMem(arr,k,i,j-1,dp));
        return dp[i][j];
    }

    
    int removals(vector<int>& arr, int k){
        int n=arr.size();
        sort(arr.begin(),arr.end());
        
        // return solveRec(arr,k,0,arr.size()-1);
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solveMem(arr,k,0,n-1,dp);
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends