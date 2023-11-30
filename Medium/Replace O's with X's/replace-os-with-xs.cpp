//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(int row,int col,vector<vector<char>> &mat,vector<vector<int>> &vis,int n,int m){
        vis[row][col]=1;
        int rd[]={0,1,-1,0};
        int cd[]={1,0,0,-1};
        for(int i=0;i<4;i++){
            int r=row+rd[i];
            int c=col+cd[i];
            if(r>=0 && r<n && c>=0 && c<m && !vis[r][c] && mat[r][c]=='O' ){
                dfs(r,c,mat,vis,n,m);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>>visited(n,vector<int>(m,0));
        //traverse all the boundary if O than find all connected O and cant be visited
        //first row
        for(int i=0;i<m;i++){
            if(mat[0][i]=='O' && visited[0][i]==0){
                dfs(0,i,mat,visited,n,m);
            }
            if(mat[n-1][i]=='O' && visited[n-1][i]==0){
                dfs(n-1,i,mat,visited,n,m);
            }
        }
        //1st col
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O' && visited[i][0]==0){
                dfs(i,0,mat,visited,n,m);
            }
            
            if(mat[i][m-1]=='O' && visited[i][m-1]==0){
                dfs(i,m-1,mat,visited,n,m);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O' && visited[i][j]!=1){
                    mat[i][j]='X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends