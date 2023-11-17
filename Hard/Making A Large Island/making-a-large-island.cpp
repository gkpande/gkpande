//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class disjointSet{
    public:
        vector<int>size;
        vector<int>parent;
        disjointSet(int n){
            size.resize(n+1,1);
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
        void unionBySize(int u,int v){
            int ulp_u=findUpar(u);
            int ulp_v=findUpar(v);
            if(ulp_u==ulp_v){
                return;
            }
            if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u]=ulp_v;
                size[ulp_v] +=size[ulp_u];
            }
            
            else{
                parent[ulp_v]=ulp_u;
                size[ulp_u]=size[ulp_v];
                 
            }
            
        }
        
        
};



class Solution
{
public:
    bool valid(int row,int col,int n){
        return (row>=0 && row<n && col>=0 && col<n);
    }
    int largestIsland(vector<vector<int>>& grid) 
    {
        int n= grid.size();
        disjointSet ds(n*n);
        //step1: make disjoint set 
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++)
            {
               if(grid[row][col]==0){
                   continue;
               } 
               //if not zero than find all adjacent element and combine them
               int dr[]={-1,0,1,0};
               int dc[]={0,1,0,-1};
               for(int k=0;k<4;k++ ){
                   int newRow=row+dr[k];
                   int newCol=col+dc[k];
                   if(valid(newRow,newCol,n) && grid[newRow][newCol]==1){
                       int node=row*n+col;
                       int adjNode=newRow*n+newCol;
                       ds.unionBySize(node,adjNode);
                   }
               }
            }
        }
        
        //step2: convert each 0 to 1 and find max size component 
        int mxSize=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1){
                    continue;
                }
                //go in all direction and find each component size
                set<int>components;
                int dr[]={-1,0,1,0};
               int dc[]={0,1,0,-1};
               for(int k=0;k<4;k++ ){
                   int newRow=row+dr[k];
                   int newCol=col+dc[k];
                   if(valid(newRow,newCol,n)){
                       if(grid[newRow][newCol]==1){
                           int adjNode=newRow*n+newCol;
                           components.insert(ds.findUpar(adjNode));
                       }
                       
                   }
               }
               //find the size of each distinct component stored in set.    
               int totalSize=0;
               for(auto it:components){
                   totalSize+=ds.size[it];
               }
               mxSize=max(mxSize,totalSize+1);
            }
        }
        for(int i=0;i<n*n;i++){
            mxSize=max(mxSize,ds.size[ds.findUpar(i)]);
        }
        return mxSize;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends