//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    // Helper function for DFS traversal
    void dfs(int v, vector<int>& vis, vector<int> adj[]) {
        vis[v] = 1;
        for (int node : adj[v]) {
            if (!vis[node]) {
                dfs(node, vis, adj);
            }
        }
    }

    int findMotherVertex(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        int motherVertex = -1;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, adj);
                motherVertex = i;
            }
        }

        // Now, check if the found motherVertex is indeed a mother vertex.
        fill(visited.begin(), visited.end(), 0);
        dfs(motherVertex, visited, adj);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                return -1; // No mother vertex found
            }
        }

        return motherVertex;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends