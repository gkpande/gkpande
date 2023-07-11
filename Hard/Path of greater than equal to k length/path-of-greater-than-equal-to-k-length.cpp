//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution {
public:
    bool dfsgraph(int k, vector<pair<int,int>>graph[],vector<int>&visited,int node){
        visited[node]=1;
        if(k<=0){
            return true;
        }
        for(auto i:graph[node]){
            if(visited[i.first]){
                continue;
                
            }
            if(i.second>=k){
                return true;
            }
                bool ans= dfsgraph(k-i.second,graph,visited,i.first);
                if(ans==1){
                    return true;
                
                }
        }
        visited[node]=0;
        return false;
    }
    bool pathMoreThanK(int V, int E, int k, int *a) 
    { 
    //   int size = sizeof(a) / sizeof(a[0]);
      
       //create graph
       vector<pair<int,int>>graph[V+1];
       int i=0;
       for(int j=0;j<E;j++){
           graph[a[i]].push_back({a[i+1],a[i+2]});
           graph[a[i+1]].push_back({a[i],a[i+2]});
           i+=3;
       }
    //   for(int i=0;i<V;i++){
    //       cout<<i<<"->";
    //       for(auto j:graph[i]){
    //           cout<<"{"<<j.first<<","<<j.second<<"}"<<" ";
    //       }
    //       cout<<endl;
    //   }
       vector<int>visited(V,0);
       visited[0]=1;
       return dfsgraph(k,graph,visited,0);
    } 
};




//{ Driver Code Starts.


int main() {
	//code
    int t;cin >> t;
    while(t--)
    {
        int V, E, K;
        cin >> V >> E >> K;
        int a[3*E + 1];
        for(int  i=0;i<3*E;i++){
            cin >> a[i];
        }
        
        Solution obj;
        if(obj.pathMoreThanK(V, E, K, a)){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends