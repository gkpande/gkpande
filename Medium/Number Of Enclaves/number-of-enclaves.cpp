//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int dx[4]={-1,0,0,1};
  int dy[4]={0,-1,1,0};
  void dfs(vector<vector<int>>&grid,int i,int j,int n,int m){
      grid[i][j]=0;
      for(int d=0;d<4;d++){
          if(i+dx[d]>=0 && i+dx[d]<n && j+dy[d]>=0 && j+dy[d]<m && grid[i+dx[d]][j+dy[d]]==1){
              dfs(grid,i+dx[d],j+dy[d],n,m);
          }
      }
  }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<m;i++){
            //check 1st row boundary havin 1 or not
            if(grid[0][i]==1){
                dfs(grid,0,i,n,m);
            }
            //check for last row boundary having 1 or not
            if(grid[n-1][i]==1){
                dfs(grid,n-1,i,n,m);
            }
        }
        for(int i=0;i<n;i++){
            //check 1st col boundary havin 1 or not
            if(grid[i][0]==1){
                dfs(grid,i,0,n,m);
            }
            //check for last col boundary having 1 or not
            if(grid[i][m-1]==1){
                dfs(grid,i,m-1,n,m);
            }
        }
        //check if any land is on or not
        int countLand=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    countLand +=1;
                }
            }
        }
        return countLand;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends