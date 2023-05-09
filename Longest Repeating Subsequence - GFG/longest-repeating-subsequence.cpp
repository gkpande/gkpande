//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	int solveRecLcs(string str1, string str2,int n,int i,int j){
	    if(i==n){
	        return 0;
	    }
	    if(j==n){
	        return 0;
	    }
	    int ans=0;
	    if(str1[i]==str2[j] && i!=j ){
	        ans=1+solveRecLcs(str1,str2,n,i+1,j+1);
	    }
	    else{
	        ans=max(solveRecLcs(str1,str2,n,i+1,j),solveRecLcs(str1,str2,n,i,j+1));
	    }
	    return ans;
	}
	int solveMemLcs(string str1, string str2,int n,int i,int j,vector<vector<int>>&dp){
	    if(i==n){
	        return 0;
	    }
	    if(j==n){
	        return 0;
	    }
	    if(dp[i][j]!=-1){
	        return dp[i][j];
	    }
	    int ans=0;
	    if(str1[i]==str2[j] && i!=j ){
	        ans=1+solveMemLcs(str1,str2,n,i+1,j+1,dp);
	    }
	    else{
	        ans=max(solveMemLcs(str1,str2,n,i+1,j,dp),solveMemLcs(str1,str2,n,i,j+1,dp));
	    }
	    dp[i][j]=ans;
	    return dp[i][j];
	}
	int solveTabLcs(string str1, string str2,int n){
	    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
	    for(int i=n-1;i>=0;i--){
	        for(int j=n-1;j>=0;j--){
	            if(str1[i]==str2[j] && i!=j ){
	                dp[i][j]=1+dp[i+1][j+1];
	            }
	            else{
	                dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
	            }
	        }
	    }
	    
	    return dp[0][0];
	}
	
	int solveSoLcs(string str1, string str2,int n){
	   vector<int>curr(n+1,0);
	   vector<int>prev(n+1,0);
	    for(int i=n-1;i>=0;i--){
	        for(int j=n-1;j>=0;j--){
	            if(str1[i]==str2[j] && i!=j ){
	                curr[j]=1+prev[j+1];
	            }
	            else{
	               curr[j]=max(curr[j+1],prev[j]);
	            }
	        }
	        prev=curr;
	    }
	    
	    return prev[0];
	}
	
	
		int LongestRepeatingSubsequence(string str){
		    int n=str.length();
		    string str1=str;
		    string str2=str;
		  //  return solveRecLcs(str1,str2,n,0,0);
		  //vector<vector<int>>dp(n,vector<int>(n,-1));
		  //return solveMemLcs(str1,str2,n,0,0,dp);
		  //return solveTabLcs(str1,str2,n);
		  return solveSoLcs(str1,str2,n);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends