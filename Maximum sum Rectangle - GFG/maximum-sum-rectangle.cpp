//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int solveNaive(int R, int C, vector<vector<int>>&M){
      int maxSum=INT_MIN;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                for(int k=i;k<R;k++){
                    for(int l=j;l<C;l++){
                        int currSum=0;
                        for(int x=i;x<=k;x++){
                            for(int y=j;y<l;y++){
                                currSum+=M[x][y];
                            }
                        }
                        maxSum=max(maxSum,currSum);
                    }
                }
            }
        }
        return maxSum;
  }
  int kanadian(vector<int>&temp,int C){
      int maxSum=INT_MIN;
      int sum=0;
      for(int i=0;i<C;i++){
          sum=sum+temp[i];
          maxSum=max(maxSum,sum);
          if(sum<0){
              sum=0;
          }
      }
      return maxSum;
  }
  int solveEfficient(int R, int C, vector<vector<int>>& M){
      int maxSum=INT_MIN;
      for(int i=0;i<R;i++){
          vector<int>temp(C,0);
          for(int j=i;j<R;j++){
              for(int k=0;k<C;k++){
                  temp[k] +=M[j][k];
              }
              int sum=kanadian(temp,C);
              maxSum=max(maxSum,sum);
          }
      }
      return maxSum;
  }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // return solveNaive(R,C,M);
        return solveEfficient(R,C,M);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends