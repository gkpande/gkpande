//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    bool detectCycle(unordered_map<int,bool>&visited,unordered_map<int,int>&parent,vector<int> adj[],int src){
        queue<int>q;
        q.push(src);
        visited[src]=true;
        parent[src]=-1;
        while(!q.empty()){
            int frontNode=q.front();
            q.pop();
            for(auto i:adj[frontNode]){
                // cout<<i;
                if(visited[i]==true && parent[frontNode]!=i){
                    return true;
                }
                else if(!visited[i]){
                    visited[i]=true;
                    parent[i]=frontNode;
                    q.push(i);
                
            }
        }
        }
        return false;
    }
    

    
    bool isCycle(int V, vector<int> adj[]) {
        
        unordered_map<int,bool>visited;
        
        unordered_map<int,int>parent;
        
        //cout<<V;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool temp=detectCycle(visited,parent,adj,i);
                if(temp==true)
                {
                    return true;
                }
            }
            
        }
        
        return false;
    
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends