//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    bool solveRec(string A, string B, string C,int m,int n,int p,int i,int j,int k){
        if(i==m && j==n && k==p){
            return true;
        }
        if(k==p){
            return false;
        }
        bool ans1=false;
        if(i<m && A[i]==C[k]){
            ans1=solveRec(A,B,C,m,n,p,i+1,j,k+1);
        }
        bool ans2=false;
        if(j<n && B[j]==C[k]){
            ans2=solveRec(A,B,C,m,n,p,i,j+1,k+1);
        }
        return ans1||ans2;
    }
    bool solveMem(string A, string B, string C,int m,int n,int p,int i,int j,int k,vector<vector<int>>&dp){
        if(i==m && j==n && k==p){
            return true;
        }
        if(k==p){
            return false;
        }
        if(dp[i][j]!=-1){
            return dp[m][n];
        }
        bool ans1=false;
        if(i<m && A[i]==C[k]){
            ans1=solveMem(A,B,C,m,n,p,i+1,j,k+1,dp);
        }
        bool ans2=false;
        if(j<n && B[j]==C[k]){
            ans2=solveMem(A,B,C,m,n,p,i,j+1,k+1,dp);
        }
        dp[m][n]=ans1||ans2;
        return dp[i][j];
    }
    
    bool solveTab(string A, string B, string C,int m,int n,int p){
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=m;i>=0;i--){
            for(int j=n;j>=0;j--){
                if(i==m && j==n){
                    dp[m][n]=1;
                    continue;
                }
                bool ans1=false;
                if(i!=m && A[i]==C[i+j]){
                    ans1=dp[i+1][j];
                }
                bool ans2=false;
                if(j!=n && B[j]==C[i+j]){
                    ans2=dp[i][j+1];
                }
                dp[i][j]=ans1||ans2;
            }
        }
        
        
        return dp[0][0];
    }
    bool solveSo(string A, string B, string C,int m,int n,int p){
        vector<int>prev(n+1,0);
        vector<int>curr(n+1,0);
        
        for(int i=m;i>=0;i--){
            for(int j=n;j>=0;j--){
                if(i==m && j==n){
                    prev[n]=1;
                    curr[n]=1;
                    continue;
                }
                bool ans1=false;
                if(i!=m && A[i]==C[i+j]){
                    ans1=prev[j];
                }
                bool ans2=false;
                if(j!=n && B[j]==C[i+j]){
                    ans2=curr[j+1];
                }
                curr[j]=ans1||ans2;
            }
            prev=curr;
        }
        
        
        return prev[0];
    }
    bool isInterleave(string A, string B, string C) 
    {
        int m=A.size();
        int n=B.size();
        int p=C.size();
        // return solveRec(A,B,C,m,n,p,0,0,0);
        // vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        // return solveMem(A,B,C,m,n,p,0,0,0,dp);
        // return solveTab(A,B,C,m,n,p);
        return solveSo(A,B,C,m,n,p);
        
        
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends