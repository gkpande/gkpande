//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isSafe(int col,int node,bool graph[101][101],vector<int>&color,int n){
        for(int nbr=0;nbr<n;nbr++){
            if(nbr!=node && graph[nbr][node]==1 && color[nbr]==col){
                return false;
            }
            
        }    
         return true;   
    }
        
    
    bool possibleColor(bool graph[101][101],vector<int>&color,int m,int n,int node){
        if(node==n){
            return true;
        }
        for(int i=1;i<=m;i++){  //i is the  color from o to m-1
            if(isSafe(i,node,graph,color,n)){
                color[node]=i;
                if (possibleColor(graph,color,m,n,node+1)){
                    return true;
                }
                else{
                    color[node]=0;
                }
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int>color(n,0);
        if(possibleColor(graph,color,m,n,0)){
            return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends