//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int solveRec(int arr[],int n,int ind,int prev){
	    if(ind==n){
	        return 0;
	    }
	    int take=0;
	    if(prev==-1){
	        take=arr[ind]+solveRec(arr,n,ind+1,ind);
	    }else{
	        if(arr[ind]>arr[prev]){
	            take=arr[ind]+solveRec(arr,n,ind+1,ind);
	        }
	    }
	    int notTake=0+solveRec(arr,n,ind+1,prev);
	    return max(take,notTake);
	}
	int solveMem(int arr[],int n,int ind,int prev,vector<vector<int>>&dp){
	    if(ind==n){
	        return 0;
	    }
	    if(dp[ind][prev+1]!=-1){
	        return dp[ind][prev+1];
	    }
	    int take=0;
	    if(prev==-1){
	        take=arr[ind]+solveMem(arr,n,ind+1,ind,dp);
	    }else{
	        if(arr[ind]>arr[prev]){
	            take=arr[ind]+solveMem(arr,n,ind+1,ind,dp);
	        }
	    }
	    int notTake=0+solveMem(arr,n,ind+1,prev,dp);
	    dp[ind][prev+1]=max(take,notTake);
	    return dp[ind][prev+1];
	}
	int maxSumIS(int arr[], int n)  
	{  
	   // return solveRec(arr,n,0,-1);
	   //memorization
	   vector<vector<int>>dp(n,vector<int>(n+1,-1));
	   return solveMem(arr,n,0,-1,dp);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends