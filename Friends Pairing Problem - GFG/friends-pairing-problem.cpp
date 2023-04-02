//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

#define MOD 1000000007
class Solution
{
public:
long long add(int a,int b){
        return (a%MOD+b%MOD)%MOD;
    }
long long mul(int a,int b){
        return (a%MOD *1LL* b%MOD)%MOD;
    }
int solve(int n){
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    int ans=add(solve(n-1),mul(n-1,solve(n-2)));
    return ans;
}
int solveMem(int n,vector<int>&dp){
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=add(solveMem(n-1,dp),mul(n-1,solveMem(n-2,dp)));
    return dp[n];
}
    int countFriendsPairings(int n) 
    { 
        //recursive solution
        // return solve(n);
        //recursive+memorization
        vector<int>dp(n+1,-1);
        return solveMem(n,dp);
        
    }
};    
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends