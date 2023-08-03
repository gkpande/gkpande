//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        // Create graph
        vector<pair<int, int>> graph[N];
        for (int i = 0; i < M; i++) {
            graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        
        // Topological ordering of graph
        vector<int> indegree(N, 0);
        for (int i = 0; i < N; i++) {
            for (auto j : graph[i]) {
                indegree[j.first]++;
            }
        }
        
        vector<int> ans;
        queue<int> q;
        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            ans.push_back(f);
            for (auto i : graph[f]) {
                indegree[i.first]--;
                if (indegree[i.first] == 0) {
                    q.push(i.first);
                }
            }
        }
        
        // Create distance vector
        vector<int> dis(N, INT_MAX);
        dis[0] = 0;
        
        // Update distance vector using correct topological order
        for (int i = 0; i < ans.size(); i++) {
            int v = ans[i];
            if (dis[v] != INT_MAX) {
                for (auto u : graph[v]) {
                    if (dis[u.first] > dis[v] + u.second) {
                        dis[u.first] = dis[v] + u.second;
                    }
                }
            }
        }
        
        for (int i = 0; i < N; i++) {
            if (dis[i] == INT_MAX) {
                dis[i] = -1;
            }
        }
        return dis;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends