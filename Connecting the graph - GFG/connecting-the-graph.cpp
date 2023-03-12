//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void makeSet(vector<int>&parent,vector<int>&rank,int n){
      for(int i=0;i<n;i++){
          parent[i]=i;
          rank[i]=0;
      }
  }
  int findParent(int node,vector<int>&parent){
      if(parent[node]==node){
          return node;
      }
      return parent[node]=findParent(parent[node],parent);
  }
  void rankUnion(int u,int v,vector<int>&parent,vector<int>&rank){
    if(rank[u]<rank[v]){
        parent[u]=v;
    }
    else if(rank[u]>rank[v]){
        parent[v]=u;
    }
    else{
        parent[u]=v;
        rank[v]++;
    }
  }
    int Solve(int n, vector<vector<int>>& edge) {
        int m=edge.size();
        vector<int>parent(n);
        vector<int>rank(n);
        makeSet(parent,rank,n);
        int countExtra=0;
        for(int i=0;i<m;i++){
            int u=findParent(edge[i][0],parent);
            int v=findParent(edge[i][1],parent);
            if(u==v){
                countExtra++;
            }
            else{
                rankUnion(u,v,parent,rank);
            }
        }
        int countComponent=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                countComponent++;
            }
        }
        if(countExtra>=countComponent-1){
            return countComponent-1;
        }
        return -1;
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