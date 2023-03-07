//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int node, unordered_map<int,bool>&visited,vector<vector<int>>& adj, stack<int>&st){
	    visited[node]=true;
	    for(auto nbr:adj[node]){
	        if(!visited[nbr]){
	            dfs(nbr,visited,adj,st);
	        }
	    }
	    st.push(node);
	}
	void reDfs(int node,unordered_map<int,bool>&visited, unordered_map<int,list<int>>&transpose){
	    visited[node]=true;
	    for(auto nbr:transpose[node] ){
	        if(!visited[nbr]){
	            reDfs(nbr,visited,transpose);
	        }
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
      //sort the graph
       stack<int>st;
       unordered_map<int,bool>visited;
       for(int i=0;i<V;i++){
           if(!visited[i]){
               dfs(i,visited,adj,st);
           }
       }
       
       //transpose the graph
       unordered_map<int,list<int>>transpose;
       for(int i=0;i<V;i++){
           visited[i]=false;
           for(auto nbr:adj[i]){
               transpose[nbr].push_back(i);
           }
       }
       //dfs call to find scc.
       int count=0;
       while(!st.empty()){
           int top=st.top();
           st.pop();
           if(!visited[top]){
               count++;
               reDfs(top,visited,transpose);
           }
       }
       
      return count; 
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends