//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        //create a distance vector
        vector<int>dist(V);
        for(int i=0;i<V;i++){
            dist[i]=INT_MAX;
        }
        
        //create set contain pair as element first is distance and second is node.
        set<pair<int,int>>st;
        
        dist[S]=0;
        st.insert(make_pair(0,S));
        
        while(!st.empty()){
            auto top=*(st.begin());   //top< distance, node>
            st.erase(top);
            int topNode=top.second;
            int topDist=top.first;
            for(auto neighbour:adj[topNode]){
                if(topDist+neighbour[1]<dist[neighbour[0]]){
                    dist[neighbour[0]]=topDist+neighbour[1];  //update distance
                    //update set
                    
                    if(st.find(make_pair(dist[neighbour[0]],neighbour[0]))!=st.end());{
                            st.erase(make_pair(dist[neighbour[0]],neighbour[0]));
                    }
                    st.insert(make_pair(dist[neighbour[0]],neighbour[0]));
                }
              
            }
        }
        return dist;
        
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends