//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void dfs(int i,int V,vector<int>adjl[],vector<int>&visited){
      visited[i]=1;
      for(auto ngh:adjl[i]){
          if(visited[ngh]==0){
              dfs(ngh,V,adjl,visited);
          }
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        int count=0;
        vector<int>adjl[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(j!=i && adj[i][j]==1){
                    adjl[i].push_back(j);
                }
            }
        }
        vector<int>visited(V+1,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,V,adjl,visited);
                count++;
            }
        }
        return count; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends