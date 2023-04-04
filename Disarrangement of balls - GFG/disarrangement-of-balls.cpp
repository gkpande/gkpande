//{ Driver Code Starts
// Initial function Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define MOD 1000000007
class Solution{
public:
long int solve(int N){
    if(N==1){
        return 0;
    }
    if(N==2){
        return 1;
    }
    
    long int ans= ((N-1)*(((solve(N-2)%MOD + solve(N-1)%MOD))%MOD))%MOD;
    return ans;
}
long int solveMem(int N,vector<long int>&dp){
    if(N==1){
        return 0;
    }
    if(N==2){
        return 1;
    }
    if(dp[N]!=0){
        return dp[N];
    }
    dp[N]= ((N-1)*(((solveMem(N-2,dp)%MOD + solveMem(N-1,dp)%MOD))%MOD))%MOD;
    return dp[N];
}
long int solveTab(int N){
    vector<long int>dp(N+1,0);
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<=N;i++){
        long int ans=(dp[i-1]+dp[i-2])%MOD;
        dp[i]=((i-1)*ans)%MOD;
    }
    return dp[N];
}

    long int disarrange(int N){
        //recursive
        // return solve(N);
        //recursive + memorization
        // vector<long int>dp(N+1,0);
        // return solveMem(N,dp);
        //tabulation
        return solveTab(N);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.disarrange(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends