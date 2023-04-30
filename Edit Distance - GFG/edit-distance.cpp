//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int solveRec(string s,string t,int i,int j){
      // base case
      if(i==s.length()){
          return t.length()-j;  //insert from t to s
      }
      if(j==t.length()){
          return s.length()-i; //delete from s
      }
      int ans=0;
      if(s[i]==t[j]){
          return solveRec(s,t,i+1,j+1);
      }
      else{
          //insert
            int insertAns=1+solveRec(s,t,i,j+1);
            //delete
            int deleteAns=1+solveRec(s,t,i+1,j);
            //replace
            int replaceAns=1+solveRec(s,t,i+1,j+1);
            ans=min(insertAns,min(deleteAns,replaceAns));
      }
      
      return ans;
  }
  int solveMem(string s,string t,int i,int j,vector<vector<int>>&dp){
      // base case
      if(i==s.length()){
          return t.length()-j;  //insert from t to s
      }
      if(j==t.length()){
          return s.length()-i; //delete from s
      }
      if(dp[i][j]!=-1){
          return dp[i][j];
      }
      int ans=0;
      if(s[i]==t[j]){
          return solveMem(s,t,i+1,j+1,dp);
      }
      else{
          //insert
            int insertAns=1+solveMem(s,t,i,j+1,dp);
            //delete
            int deleteAns=1+solveMem(s,t,i+1,j,dp);
            //replace
            int replaceAns=1+solveMem(s,t,i+1,j+1,dp);
            dp[i][j]=min(insertAns,min(deleteAns,replaceAns));
      }
      
      return dp[i][j];
  }
    int editDistance(string s, string t) {
        //recursive solution
        // return solveRec(s,t,0,0);
        //rec+mem
        vector<vector<int>>dp(s.length(),vector<int>(t.length(),-1));
        return solveMem(s,t,0,0,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends