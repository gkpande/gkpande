//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class disjointSet{
    public:
        vector<int>parent;
        vector<int>rank;
    disjointSet(int n){
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        rank.resize(n,0);
    }
    
    int findUlp(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findUlp(parent[node]);
    }
    void unionByRank(int u , int v){
        int ulp_u=findUlp(u);
        int ulp_v=findUlp(v);
        if(ulp_u==ulp_v){
            return ;
        }
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    
    
};

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edges) {
        disjointSet ds(n);
        int extraEdges=0;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int ulp_u=ds.findUlp(u);
            int ulp_v=ds.findUlp(v);
            if(ulp_u==ulp_v){
                extraEdges++;
            }
            else{
                ds.unionByRank(u,v);
            }
        }
        int nc=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i){
                nc++;
            }
        }
        return extraEdges>=nc-1?nc-1:-1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends