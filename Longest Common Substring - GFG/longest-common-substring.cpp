//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int solveTab(string &S1, string &S2, int n, int m){
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int res=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(S1[i-1]==S2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    res=max(res,dp[i][j]);
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return res;
    }
    int solveSo(string &S1, string &S2, int n, int m){
        vector<int>prev(m+1,0);
        vector<int>curr(m+1,0);
        int res=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(S1[i-1]==S2[j-1]){
                    curr[j]=1+prev[j-1];
                    res=max(res,curr[j]);
                }
                else{
                    curr[j]=0;
                }
            }
            prev=curr;
        }
        return res;
    }
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // return solveTab(S1,S2,n,m);
        return solveSo(S1,S2,n,m);
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends