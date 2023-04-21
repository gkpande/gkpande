//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	int solveRec(int n){
	    if(n==0){
	        return 0;
	    }
	    int ans=n;
	    for(int i=1;i*i<=n;i++){
	        int temp=i*i;
	        ans=min(ans,1+solveRec(n-temp));
	    }
	    return ans;
	}
	int solveMem(int n,vector<int>&dp){
	    if(n==0){
	        return 0;
	    }
	    if(dp[n]!=-1){
	        return dp[n];
	    }
	    int ans=n;
	    for(int i=1;i*i<=n;i++){
	        int temp=i*i;
	        ans=min(ans,1+solveMem(n-temp,dp));
	    }
	    dp[n]=ans;
	    return dp[n];
	}
	int solveTab(int n){
	    vector<int>dp(n+1,INT_MAX);
	    dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                int temp=j*j;
                dp[i]=min(dp[i],1+dp[i-temp]);
            }
        }
	    
	    return dp[n];
	}
	int MinSquares(int n)
	{
	   // return solveRec(n);
	   //vector<int>dp(n+1,-1);
	   //return solveMem(n,dp);
	   return solveTab(n);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends