//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(unordered_map<int, set<int>>&adjList,vector<int>&ans,unordered_map<int,bool>&visited,int node){
        queue<int>q;
        q.push(node);
        visited[node]=1;
        while(!q.empty()){
            
            int frontNode=q.front();
            
            q.pop();
            
            ans.push_back(frontNode);
            
            for(auto i:adjList[frontNode]){
                if(!visited[i]){
                    q.push(i);
                    visited[i]=1;
                }
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int>ans;
       
        unordered_map<int, set<int>>adjList;
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                adjList[i].insert(adj[i][j]);
            }
        }
        unordered_map<int,bool>visited;
        
        //for(int i=0;i<V;i++){
            bfs(adjList,ans,visited,0);
       //}
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends