//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst)
        {
            int m=edges.size();
            vector<pair<int,int>>graph[n+1];
            for(int i=0;i<m;i++){
                graph[edges[i][0]].push_back({edges[i][1],0});
                graph[edges[i][1]].push_back({edges[i][0],1});
            }
            // for(int i=1;i<=n;i++){
            //     for(auto j:graph[i]){
            //         cout<<j.first<<","<<j.second<<"-";
            //     }
            //     cout<<endl;
            // }
            vector<int>dist(n+1,INT_MAX);//distance array
            dist[src]=0;
            set<pair<int,int>>st;//pair{distance,node}
            st.insert({0,src});
            while(!st.empty()){
                auto p=*(st.begin());
                
                st.erase(st.begin());
                int node=p.second;
                int dest=p.first;
                for(auto adj:graph[node]){
                    if(dest+adj.second<dist[adj.first]){
                        if(st.find({dist[adj.first],adj.first})!=st.end()){
                            st.erase({dist[adj.first],adj.first});
                        }
                        dist[adj.first]=dest+adj.second;
                        st.insert({dist[adj.first],adj.first});
                    }
                    
                    
                }
            }
            if(dist[dst]==INT_MAX){
                return -1;
            }
            return dist[dst];
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> edges(m,vector<int> (2));
        for(auto &j:edges)
            for(auto &i:j)
                cin>>i;
        int src,dst;
        cin>>src>>dst;
        Solution s;
        cout<<s.minimumEdgeReversal(edges,n,src,dst)<<endl;
    }
    return 0;
}
// } Driver Code Ends