//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    int n=prerequisites.size();
	    // create a graph
	   vector<int>graph[N+1];
	   for(int i=0;i<n;i++){
	       graph[prerequisites[i].first].push_back(prerequisites[i].second);
	   }
	   // create indegree array
	   vector<int>indegree(N,0);
	   for(int i=0;i<N;i++){
	       for(auto j:graph[i]){
	           indegree[j]++;
	       }
	   }
	   //create a queue
	   queue<int>q;
	   //find all the vertices with indegree is 0 push into queue.
	   for(int i=0;i<N;i++){
	       if(indegree[i]==0){
	           q.push(i);
	       }
	   }
	   //use bfs algorithm
	   while(!q.empty()){
	       int qsize=q.size();
	       while(qsize>0){
	           int front=q.front();
	           q.pop();
	           for(auto j:graph[front]){
	               indegree[j]--;
	               if(indegree[j]==0){
	                   q.push(j);
	               }
	           }
	           qsize--;
	       }
	   }
	   for(auto i:indegree){
	       if(i>0){
	           return false;
	       }
	   }
	   return true;
	   
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends