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
    //for any person he will single or he will pair with remaining n-1 person
    //he is single find way of remaining f(n-1)+he pair with n-1 * find for f(n-1)
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
int solveTab(int n){
    vector<int>dp(n+1,-1);
    dp[1]=1;
    
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=add(dp[i-1],mul(i-1,dp[i-2]));
    }
    return dp[n];
}
int solveSo(int n){
    if(n==1){
        return 1;
    }
    int prev1=1;
    
    int prev2=2;
    for(int i=3;i<=n;i++){
        int ans=add(prev2,mul(i-1,prev1));
        prev1=prev2;
        prev2=ans;
    }
    return prev2;
}

    int countFriendsPairings(int n) 
    { 
        //recursive solution
        // return solve(n);
        //recursive+memorization
        // vector<int>dp(n+1,-1);
        // return solveMem(n,dp);
        //tabulation method
        // return solveTab(n);
        //space optimization
        return solveSo(n);
        
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