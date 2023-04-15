//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        //create a graph
        vector<pair<int,int>>graph[n];
        for(int i=0;i<flights.size();i++){
            graph[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        //create a distance vector
        vector<int>dist(n,1e9);
        dist[src]=0;
        //create a queue
        queue<pair<int,pair<int,int>>>q;
        //initialize queue
        q.push({0,{src,0}});
        while(!q.empty()){
            auto front=q.front();
            int stop=front.first;
            int node=front.second.first;
            int cost=front.second.second;
            q.pop();
            if(stop>K){
                continue;
            }
            for(auto j:graph[node]){
                if(cost+j.second<dist[j.first] && stop<=K){
                    dist[j.first]=cost+j.second;
                    q.push({stop+1,{j.first,cost+j.second}});
                }
            }
        }
        if(dist[dst]==1e9){
            return -1;
        }
        return dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends