//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  bool isPalindrom(string S,int index, int i){
      while(index<=i){
          if(S[index]!=S[i]){
              return false;
          }
          index++;
          i--;
      }
      return true;
  }
  void solve(string S,vector<vector<string>>&ans,int index,vector<string>&path){
      if(index==S.length()){
          ans.push_back(path);
      }
      for(int i=index;i<S.length();i++){
          if(isPalindrom(S,index,i)){
              path.push_back(S.substr(index,i-index+1));
              solve(S,ans,i+1,path);
              path.pop_back();
          }
      }
  }
    vector<vector<string>> allPalindromicPerms(string S) {
        vector<vector<string>>ans;
        vector<string>path;
        solve(S,ans,0,path);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends