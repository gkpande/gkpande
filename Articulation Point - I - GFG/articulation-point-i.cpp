//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void dfs(int node,int par,vector<int>&disc,vector<int>&low,unordered_map<int,bool>&visited,vector<int>&ap,int &timer,vector<int>adj[]){
      disc[node]=low[node]=timer++;
      visited[node]=true;
      int child=0;
      
      for(auto nbr:adj[node]){
          if(nbr==par){
              continue;
          }
          if(!visited[nbr]){
              dfs(nbr,node,disc,low,visited,ap,timer,adj);
              low[node]=min(low[node],low[nbr]);
              if(low[nbr]>=disc[node] && par!=-1){
                //   ap.push_back(node);
                ap[node]=true;
                  
              }
              child++;
          }
          else{
              low[node]=min(low[node],disc[nbr]);
          }
      }
      if(par==-1 && child>1){
        //   ap.push_back(node);
        ap[node]=true;
      }
  }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int>disc(V,-1);
        vector<int>low(V,-1);
       
        unordered_map<int,bool>visited;
        vector<int>ap(V);
        int timer=0;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,-1,disc,low,visited,ap,timer,adj);
            }
        }
        //  sort(ap.begin(),ap.end());
        vector<int>ans;
        int c=0;
        for(int i=0;i<V;i++){
            if(ap[i]==true){
                ans.push_back(i);
                c++;
            }
        }
        if(c==0){
            ans.push_back(-1);
            return ans;
        }
        return ans;
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
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends