//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int solveRec(int arr[],int n,int sum){
	    if(n==0 && sum>0){
	        return 0;
	    }
	    if(n==0 && sum==0){
	        return 1;
	    }
	    if(n==1){
	        if(sum==0 && arr[0]==0){
	             return 2;
	        }
	        else if(sum==0){
	            return 1;
	        }
	        else if(arr[0]==sum){
	            return 1;
	        }
	        else{
	            return 0;
	        }  
	    }
	    if(arr[n-1]<=sum){
	        return solveRec(arr,n-1,sum-arr[n-1]) +solveRec(arr,n-1,sum);
	    }
	    else{
	        return solveRec(arr,n-1,sum);
	    }
	}
	int solveMem(int arr[],int n,int sum,vector<vector<int>>&dp){
	    if(n==0 && sum>0){
	        return 0;
	    }
	    if(n==0 && sum==0){
	        return 1;
	    }
	    if(n==1){
	        if(sum==0 && arr[0]==0){
	             return 2;
	        }
	        else if(sum==0){
	            return 1;
	        }
	        else if(arr[0]==sum){
	            return 1;
	        }
	        else{
	            return 0;
	        }  
	    }
	    if(dp[sum][n]!=-1){
	        return dp[sum][n];
	    }
	    if(arr[n-1]<=sum){
	        dp[sum][n]= (solveMem(arr,n-1,sum-arr[n-1],dp) +solveMem(arr,n-1,sum,dp))%1000000007;
	        return dp[sum][n]%1000000007;
	    }
	    else{
	        return solveMem(arr,n-1,sum,dp);
	    }
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    //rec
        // return solveRec(arr,n,sum);
        //mem
        vector<vector<int>>dp(sum+1,vector<int>(n+1,-1));
        return solveMem(arr,n,sum,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends