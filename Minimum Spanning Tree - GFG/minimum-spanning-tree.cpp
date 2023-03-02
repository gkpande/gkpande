//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int>key(V);
        vector<bool>smt(V);
        vector<int> parent(V);
        for(int i=0;i<V;i++){
            key[i]=INT_MAX;
            smt[i]=false;
            parent[i]=-1;
        }
        key[0]=0;
        // smt[0]=true;
        parent[0]=-1;
        for(int i=0;i<V;i++){
            int min=INT_MAX;
            int minNode;
            for(int j=0;j<V;j++){
                if(key[j]<min && smt[j]==false){
                    min=key[j];
                    minNode=j;
                }
            }
            smt[minNode]=true;
            for(auto k:adj[minNode]){
                int v=k[0];
                int w=k[1];
                if(smt[v]==false && w<key[v]){
                    key[v]=w;
                    parent[v]=minNode;
                }
            }
            
        }
        int mstSum=0;
        for(int i=V-1;i>0;i--){
            mstSum+=key[i];
        }
        return mstSum;
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends