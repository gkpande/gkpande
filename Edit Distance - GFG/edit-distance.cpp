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
  int solveTab(string s,string t){
      vector<vector<int>>dp(s.length()+1,vector<int>(t.length()+1,0));
      for(int j=0;j<=t.length();j++){
          dp[s.length()][j]=t.length()-j;
          
      }
      for(int i=0;i<=s.length();i++){
          dp[i][t.length()]=s.length()-i;
          
      }
      for(int i=s.length()-1;i>=0;i--){
          for(int j=t.length()-1;j>=0;j--){
              int ans=0;
              if(s[i]==t[j]){
                  ans=dp[i+1][j+1];
              }
              else{
                    //insert
                    int insertAns=1+dp[i][j+1];
                    //delete
                    int deleteAns=1+dp[i+1][j];
                    //replace
                    int replaceAns=1+dp[i+1][j+1];
                    ans=min(insertAns,min(deleteAns,replaceAns));
                }
            dp[i][j]=ans;
          }
      }
      return dp[0][0];
  }
    int editDistance(string s, string t) {
        //recursive solution
        // return solveRec(s,t,0,0);
        //rec+mem
        // vector<vector<int>>dp(s.length(),vector<int>(t.length(),-1));
        // return solveMem(s,t,0,0,dp);
        //Tabulation
        return solveTab(s,t);
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