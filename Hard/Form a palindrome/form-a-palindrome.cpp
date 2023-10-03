//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

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
    int countMin(string str){
        int n=str.length();
        string revstr=str;
       reverse(revstr.begin(),revstr.end());
        return n-solve(str,revstr);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends