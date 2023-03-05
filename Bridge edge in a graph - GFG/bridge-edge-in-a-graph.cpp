//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    void dfs(int node, int parent, vector<int>&dis, vector<int>&low ,  unordered_map<int ,bool>&visited, int &timer ,vector<int>adj[],int &result,int c,int d){
        dis[node]=timer;
        low[node]=timer;
        timer++;
        visited[node]=true;
        for(auto nigh:adj[node]){
            if(nigh==parent){
                continue;
            }
            if(!visited[nigh]){
                dfs(nigh,node,dis,low,visited,timer,adj,result,c,d);
                low[node]=min(low[node],low[nigh]);
                // check for bridge
                if(low[nigh]>dis[node]){
                    if((node==c && nigh==d) || (node==d && nigh==c)){
                        // cout<<"no";
                        // cout<<"c-"<<node<<"d-"<<nigh;
                        result=1;
                        // return;
                    }
                }
                
                
            }
            else{
                low[node]=min(low[nigh],low[node]);
            }
        }
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // cout<<"no of V="<<V;
        // cout<<"c-"<<c<<" d-"<<d;
       vector<int>dis(V);
       vector<int>low(V);
       int result=0;
       int timer=1;
       unordered_map<int ,bool>visited;
       for(int i=0;i<V;i++){
           dis[i]=-1;
           low[i]=-1;
       }
      for(int i=0;i<V;i++){
          if(!visited[i]){
            //   cout<<"node call to "<<i;
               dfs(i,-1,dis,low,visited,timer,adj,result,c,d);
          }
      }
       return result;
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
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends