//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void bfs(vector<vector<char>>& grid,vector<vector<int>>& visited,int n,int m,int i,int j){
        queue<pair<int,int>>q;
        q.push({i,j});
        visited[i][j]=0;
        while(!q.empty()){
            int k=q.front().first;
            int l=q.front().second;
            q.pop();
            //left
            if(l-1>=0 && visited[k][l-1]==0 && grid[k][l-1]=='1'){
                q.push({k,l-1});
                visited[k][l-1]=1;
            }
            //right
            if(l+1<m && visited[k][l+1]==0 && grid[k][l+1]=='1'){
                q.push({k,l+1});
                visited[k][l+1]=1;
            }
            //up
            if(k-1>=0 && visited[k-1][l]==0 && grid[k-1][l]=='1'){
                q.push({k-1,l});
                visited[k-1][l]=1;
            }
            //down
            if(k+1<n && visited[k+1][l]==0 && grid[k+1][l]=='1'){
                q.push({k+1,l});
                visited[k+1][l]=1;
            }
            //ludiagonal
            if(k-1>=0 && l-1>=0 && visited[k-1][l-1]==0 && grid[k-1][l-1]=='1'){
                q.push({k-1,l-1});
                visited[k-1][l-1]=1;
            }
            //urdiagonal
            if(k-1>=0 && l+1<m && visited[k-1][l+1]==0 && grid[k-1][l+1]=='1'){
                q.push({k-1,l+1});
                visited[k-1][l+1]=1;
            }
            //rddiagonal
            if(k+1<n && l+1<m && visited[k+1][l+1]==0 && grid[k+1][l+1]=='1'){
                q.push({k+1,l+1});
                visited[k+1][l+1]=1;
            }
            //lddiagonal
            if(k+1<n && l-1>=0 && visited[k+1][l-1]==0 && grid[k+1][l-1]=='1'){
                q.push({k+1,l-1});
                visited[k+1][l-1]=1;
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    bfs(grid,visited,n,m,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends