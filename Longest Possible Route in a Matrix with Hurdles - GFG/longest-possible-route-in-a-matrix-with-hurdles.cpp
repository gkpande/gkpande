//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
void solve(vector<vector<int>> matrix,vector<vector<int>>&visited,int i, int j, int xd, int yd,int &pathl,int path,int n ,int m){
    //base case
    if(i==xd && j==yd){
        pathl=max(pathl,path);
        return;
    }
    //left
    if(j-1>=0 && visited[i][j-1]==0 && matrix[i][j-1]==1){
        visited[i][j-1]=1;
        solve(matrix,visited,i,j-1,xd,yd,pathl,path+1,n,m);
        visited[i][j-1]=0;
    }
    //right
    if(j+1<m && visited[i][j+1]==0 && matrix[i][j+1]==1){
        visited[i][j+1]=1;
        solve(matrix,visited,i,j+1,xd,yd,pathl,path+1,n,m);
        visited[i][j+1]=0;
    }
    //up
    if(i-1>=0 && visited[i-1][j]==0 && matrix[i-1][j]==1){
        visited[i-1][j]=1;
        solve(matrix,visited,i-1,j,xd,yd,pathl,path+1,n,m);
        visited[i-1][j]=0;
    }
    //down
    if(i+1<n && visited[i+1][j]==0 && matrix[i+1][j]==1){
        visited[i+1][j]=1;
        solve(matrix,visited,i+1,j,xd,yd,pathl,path+1,n,m);
        visited[i+1][j]=0;
    }
    return;
}
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        if(matrix[xs][ys]==0){
            return -1;
        }
       int n=matrix.size();
       int m=matrix[0].size();
       vector<vector<int>>visited(n,vector<int>(m,0));
       int pathl=-1;
       visited[xs][ys]=1;
       solve(matrix,visited,xs,ys,xd,yd,pathl,0,n,m);
       return pathl;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends