//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfsCycle(int i,unordered_map<int, bool>&visited,unordered_map<int, bool>&dfsVisited,vector<int> adj[]){
        visited[i]=true;
        dfsVisited[i]=true;
        for(auto j:adj[i]){
            if(visited[j]==true && dfsVisited[j]==true){
                return true;
            }
            else if(!visited[j]){
                bool temp=dfsCycle(j,visited,dfsVisited,adj);
                if(temp==true){
                    return true;
                }
            }
        }
        dfsVisited[i]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        unordered_map<int, bool>visited;
        unordered_map<int,bool>dfsVisited;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool temp=dfsCycle(i,visited,dfsVisited,adj);
                if(temp==true){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends