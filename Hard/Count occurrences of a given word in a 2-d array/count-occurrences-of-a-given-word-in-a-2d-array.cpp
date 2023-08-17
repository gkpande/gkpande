//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    void solve(vector<vector<char> > &mat, string t,int r,int c,int i,int &ans,int n,int m,vector<vector<int>>&visited){
           if(i==t.length()-1){
               ans++;
               return;
           }
           visited[r][c]=1;
           //right
           if(c+1<m && visited[r][c+1]==0 && mat[r][c+1]==t[i+1]){
               solve(mat,t,r,c+1,i+1,ans,n,m,visited);
           }
           //down
           if(r+1<n && visited[r+1][c]==0 && mat[r+1][c]==t[i+1]){
               solve(mat,t,r+1,c,i+1,ans,n,m,visited);
           }
           //left
           if(c-1>=0 && visited[r][c-1]==0 && mat[r][c-1]==t[i+1]){
               solve(mat,t,r,c-1,i+1,ans,n,m,visited);
           }
           //up
           if(r-1>=0 && visited[r-1][c]==0 && mat[r-1][c]==t[i+1]){
               solve(mat,t,r-1,c,i+1,ans,n,m,visited);
           }
           visited[r][c]=0;
    }
    int findOccurrence(vector<vector<char> > &mat, string target){
        int ans=0;
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if( mat[r][c]==target[0]){
                    
                    solve(mat,target,r,c,0,ans,n,m,visited);
                    
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<vector<char> > mat(R);
        for (int i = 0; i < R; i++) {
            mat[i].resize(C);
            for (int j = 0; j < C; j++) cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout<<obj.findOccurrence(mat,target)<<endl;
    }
}

// } Driver Code Ends