//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    void dfs(int row,int col,int n ,int m,vector<vector<int>>& vis,vector<vector<int>>& grid,
        vector<pair<int,int>>&list,set<vector<pair<int,int>>>&shape,int row0,int col0){
            vis[row][col]=1;
            list.push_back({row-row0,col-col0});
            int dr[]={1,0,-1,0};
            int dc[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int newr=row+dr[i];
                int newc=col+dc[i];
                if(newr<n && newr>=0 && newc<m && newc>=0 && !vis[newr][newc] && grid[newr][newc]==1){
                    
                    dfs(newr,newc,n,m,vis,grid,list,shape,row0,col0);
                }
            }
        }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        //find the shape of connected components 
        //store them in a set
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>>shape;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    vector<pair<int,int>>list;
                    dfs(i,j,n,m,vis,grid,list,shape,i,j);
                    shape.insert(list);
                }
                
            }
        }
        return shape.size();
        
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends