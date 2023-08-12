//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int solveRec(int coins[], int m, int v,int i){
	    if(v==0){
	        return 0;
	    }
	    if(i>=m && v!=0){
	        return -1;
	    }
	    int take=0;
	    int notTake=0;
	    if(coins[i]<=v){
	        take=1+solveRec(coins,m,v-coins[i],i);
	    }
	    notTake=0+solveRec(coins,m,v,i+1);
	    if(take>0 && notTake>0){
	        return min(take,notTake);
	    }
	    if(take<=0 && notTake<=0){
	        return -1;
	    }
	    else if(take<=0){
	        return notTake;
	    }
	    else if(notTake<=0){
	        return take;
	    }
	    
	}
	int solveMem(int coins[], int m, int v,int i,vector<vector<int>>&dp){
	    if(v==0){
	        return 0;
	    }
	    if(i>=m && v!=0){
	        return -1;
	    }
	    if(dp[i][v]!=-1){
	        return dp[i][v];
	    }
	    int take=0;
	    int notTake=0;
	    if(coins[i]<=v){
	        take=1+solveMem(coins,m,v-coins[i],i,dp);
	    }
	    notTake=0+solveMem(coins,m,v,i+1,dp);
	    if(take>0 && notTake>0){
	        dp[i][v] =min(take,notTake);
	    }
	    else if(take<=0 && notTake<=0){
	        return -1;
	         
	    }
	    else if(take<=0){
	        dp[i][v] =notTake;
	         
	    }
	    else if(notTake<=0){
	         dp[i][v] =take;
	          
	    }
	   return dp[i][v];
	}
	
	int minCoins(int coins[], int M, int V) 
	{ 
	    int ans;
	   // ans=solveRec(coins,M,V,0);
	    //solve Mem
	    vector<vector<int>>dp(M+1,vector<int>(V+1,-1));
	    ans=solveMem(coins,M,V,0,dp);
	    if(ans==-1){
	        return -1;
	    }
	     return ans;
	    
	    
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends