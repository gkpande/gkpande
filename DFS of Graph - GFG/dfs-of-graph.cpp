//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(unordered_map<int,bool>&visited,vector<int>adj[],vector<int>&ans,int node){
        if(!visited[node]){
            visited[node]=1;
            ans.push_back(node);
            for(auto i:adj[node]){
                dfs(visited,adj,ans,i);    
            }
            
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        unordered_map<int,bool>visited;
        vector<int>ans;
        //unordered_map<int,vector<int>>adjList;
        //for(int i=0;i<V;i++){
            //for(int j=0;j<adj[i].size();j++){
               // adjList[i].push_back(adj[i][j]);
           // }
        //}
        dfs(visited,adj,ans,0);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends