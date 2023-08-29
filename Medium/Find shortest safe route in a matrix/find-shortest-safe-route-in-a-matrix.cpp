//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
int arr[2][4]={{0,1,0,-1},{-1,0,1,0}};
void markeUnSafeSate(vector<vector<int>> &mat,int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(mat[i][j]==0){
                for(int k=0;k<4;k++){
                    int newr=i+arr[0][k];
                    int newc=j+arr[1][k];
                    if(newr>=0 && newr<r && newc>=0 && newc<c && mat[newr][newc]==1){
                        mat[newr][newc]=-1;
                    }
                }
            }
        }
    }
}
void solve(vector<vector<int>> &mat,vector<vector<int>> &vis,int i,int j,int step,int row,int col,int &ans){
    queue<pair<pair<int,int>,int>>q;
    q.push({{i,j},step});
    vis[i][j]=1;
    while(!q.empty()){
        auto p=q.front();
        int r=p.first.first;
        int c=p.first.second;
        q.pop();
        step=p.second;
        if(r==col-1){
            ans=min(ans,step);
            continue;
        }
        for(int k=0;k<4;k++){
            int newr=r+arr[0][k];
            int newc=c+arr[1][k];
            if(newr>=0 && newr<r && newc>=0 && newc<c && mat[newr][newc]!=0 && !vis[newr][newc]){
                q.push({{newr,newc},step+1});
                vis[newr][newc]=1;
            }
        }
        
    }
      
    
}
    int findShortestPath(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m));
        int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
        //mark unsafe state as -1
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mat[i][j] == 0) {
                    for(int k=0;k<4;k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(nx>=0 and ny>=0 and nx<n and ny<m and mat[nx][ny] == 1)
                            mat[nx][ny] = -1;
                    }
                }
            }
        }
        
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++) {
            if(mat[i][0] == 1) {
                q.push({0,{i,0}});
                vis[i][0] = 1;
            }
        }
        
        int ans = INT_MAX;
        while(!q.empty()) {
            int dist = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
                
            if(c == m - 1)
                ans = min(ans,dist+1);    
            
            for(int k=0;k<4;k++) {
                int nx = r + dx[k];
                int ny = c + dy[k];
                
                if(nx>=0 and ny>=0 and nx<n and ny<m and mat[nx][ny] == 1 and !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    q.push({dist+1,{nx,ny}});
                }
            }
        }
        
        return ans == INT_MAX ? -1 : ans;

        // int row=mat.size();
        // int col=mat[0].size();
        // //mark all unsafe state as -1;
        // markeUnSafeSate(mat,row,col);
        // //mark all unsafe state to 0
        // for(int i=0;i<row;i++){
        //     for(int j=0;j<col;j++){
        //         if(mat[i][j]==-1){
        //             mat[i][j]=0;
        //         }
        //     }
        // }
        // //create a visited arr
        // vector<vector<int>>vis(row,vector<int>(col,0));
        // int fans=INT_MAX;
        // int ans=INT_MAX;
        // //traverse to all cell of first column in dfs traversal
        // for(int i=0;i<row;i++){
        //     vis[i][0]=1;
        //     int ans=INT_MAX;
        //     solve(mat,vis,i,0,1,row,col,ans);
        //     fans=min(fans,ans);
        // }
        // return fans==INT_MAX?-1:fans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends