//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends

#define MOD 1000000007
class Solution{
    
    public:
    long long add(int a,int b){
        return (a%MOD+b%MOD)%MOD;
    }
    long long mul(int a,int b){
        return (a%MOD *1LL* b%MOD)%MOD;
    }
    long long solve(int n,int k){
        if(n==1){
            return k;
        }
        if(n==2){
            return add(k,mul(k,k-1));
        }
        int ans= add(mul(solve(n-2,k),k-1),mul(solve(n-1,k),k-1));
        return ans;
    }
    long long solveMem(int n,int k,vector<long long>&dp){
        if(n==1){
            return k;
        }
        if(n==2){
            return add(k,mul(k,k-1));
        }
        if(dp[n]!=-1){
            
            return dp[n];
        }
        dp[n]= add(mul(solveMem(n-2,k,dp),k-1),mul(solveMem(n-1,k,dp),k-1));
        return dp[n];
    }
    long long countWays(int n, int k){
      //recurive solution
    //   return solve(n,k);
    //add memorization
    vector<long long>dp(n+1,-1);
    return solveMem(n,k,dp);
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends