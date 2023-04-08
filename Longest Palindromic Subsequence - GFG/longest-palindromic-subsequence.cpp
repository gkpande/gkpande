//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int solve(string A,string str){
      vector<int>curr(str.size()+1,0);
      vector<int>next(str.size()+1,0);
      int n=str.size();
      for(int i=A.size()-1;i>=0;i--){
          for(int j=n-1;j>=0;j--){
              if(A[i]==str[j]){
                  curr[j]=1+next[j+1];
              }
              else{
                  curr[j]=max(curr[j+1],next[j]);
              }
          }
          next=curr;
      }
      return curr[0];
  }
    int longestPalinSubseq(string A) {
        string revstr=A;
       reverse(revstr.begin(),revstr.end());
       return solve(A,revstr);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends