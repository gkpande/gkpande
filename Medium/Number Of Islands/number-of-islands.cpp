//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class disjointSet{
    public:
        vector<int>rank;
        vector<int>parent;
        disjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1,0);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }
        int findUpar(int node){
            if(node==parent[node]){
                return node;
            }
            return parent[node]=findUpar(parent[node]);
        }
        void unionByRank(int u,int v){
            int ulp_u=findUpar(u);
            int ulp_v=findUpar(v);
            if(ulp_u==ulp_v){
                return;
            }
            if(rank[ulp_u]<rank[ulp_v]){
                parent[ulp_u]=ulp_v;
            }
            else if(rank[ulp_v]<rank[ulp_u]){
                parent[ulp_v]=ulp_u;
            }
            else{
                parent[ulp_v]=ulp_u;
                rank[ulp_u]++;    
            }
            
        }
        
        
};
class Solution {
    private:
    bool valid(int row,int col,int n,int m){
        return (row>=0 && row<n && col>=0 && col<m );
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        disjointSet ds(n*m);
        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<int>ans;
        int cnt=0;
        for(auto it:operators){
            int row=it[0];
            int col=it[1];
            if(visited[row][col]==1){
                ans.push_back(cnt);
                continue;
            }
            visited[row][col]=1;
            cnt++;//assume the number of island increases
            //row,col-1  left
            //row,col+1 right
            //row-1 col up
            //row+1,col down
            int dr[]={0,0,-1,1};
            int dc[]={-1,1,0,0};
            
            
            for(int i=0;i<4;i++){
                int newRow=row+dr[i];
                int newCol=col+dc[i];
                
                if(valid(newRow,newCol,n,m)){
                    if(visited[newRow][newCol]){
                        int node=row*m+col;
                        int newNode=newRow*m+newCol;
                        if(ds.findUpar(newNode)!=ds.findUpar(node)){
                            cnt--;
                            ds.unionByRank(node,newNode);
                        }
                    }
                    
                }
            }
            ans.push_back(cnt);
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends