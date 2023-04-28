//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
      vector <int> maximumDistance(vector<vector<int>> edges,int v,int e,int src)
      {
          vector<int>indegree(v,0);
           //create distance array
           vector<int>distance(v,INT_MIN);
           distance[src]=0;
           //create topological order array
           vector<int>topoLog;
           //create graph
           vector<pair<int,int>> graph[v];
           for(int i=0;i<e;i++){
               graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
               indegree[edges[i][1]]++;
           }
           queue<int>q;
	       for(int i=0;i<v;i++){
	            if(indegree[i]==0){
	                q.push(i);
	            }
	        }
	        while(!q.empty()){
	            int front=q.front();
	            topoLog.push_back(front);
	            q.pop();
	            for(auto j:graph[front]){
	                indegree[j.first]--;
	                if(indegree[j.first]==0){
	                    q.push(j.first);
	                }
	            }
	        }
	       // for(int j=0;j<v;j++){
	       //     cout<<topoLog[j]<<"--";
	       // }
	        int i=0;
	        
	        while(topoLog[i]!=src){
	            i++;
	        }
	       // cout<<topoLog[i]<<"--"<<i<<"--"<<distance[topoLog[i]];
	        while(i<v){
	            for(auto j:graph[topoLog[i]]){
	                if(distance[topoLog[i]]!=INT_MIN && distance[topoLog[i]]+j.second>distance[j.first]){
	                    distance[j.first]=distance[topoLog[i]]+j.second;
	                }
	            }
	            i++;
	        }
           return distance;
      }
};

//{ Driver Code Starts.

int main() {
  
    int t;
    cin>>t;
    while(t--)
    {

        int v,e;
        cin>>v>>e;
     
        int src;
        cin>>src;
        vector<vector<int>> edges(e,vector<int> (3));
        for(auto &j:edges)
          cin>>j[0]>>j[1]>>j[2];

        Solution s;
        vector <int> ans=s.maximumDistance(edges,v,e,src);
        for(auto j:ans)
        {
            if(j==INT_MIN)
              cout<<"INF ";
            else
              cout<<j<<" ";
        }
        cout<<endl;
    } 
    return 0;
 
}
// } Driver Code Ends