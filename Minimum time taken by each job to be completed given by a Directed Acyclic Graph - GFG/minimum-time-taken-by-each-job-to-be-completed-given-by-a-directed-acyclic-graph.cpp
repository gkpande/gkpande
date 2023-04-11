//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> minimumTime(int n,vector<vector<int>> &edges,int m)
        {
            vector<int>graph[n+1];
            for(int i=0;i<m;i++){
                graph[edges[i][0]].push_back(edges[i][1]);
            }
            vector<int>indegree(n+1,0);
            for(int i=1;i<=n;i++){
                for(auto j:graph[i]){
                    indegree[j]++;
                }
            }
            vector<int>visited(n+1,0);
            queue<int>q;
            for(int i=1;i<=n;i++){
                if(indegree[i]==0){
                    q.push(i);
                    visited[i]=1;
                }
            }
            vector<int>time(n,0);
            int count=1;
            while(!q.empty()){
                int qsize=q.size();
                while(qsize>0){
                   int front=q.front();
                    q.pop();
                    for(auto i:graph[front]){
                        indegree[i]--;
                        if(indegree[i]==0){
                            q.push(i);
                        }
                        
                    }
                    time[front-1]=count;
                    qsize--;
                }
                count++;
                
                
            }
            return time;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m;
        cin>>m;
        vector<vector<int>> edges(m,vector<int>(2));
        for(int i=0;i<m;i++)
            cin>>edges[i][0]>>edges[i][1];
        Solution s;
        vector<int> ans=s.minimumTime(n,edges,m);
        for(auto j:ans)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends