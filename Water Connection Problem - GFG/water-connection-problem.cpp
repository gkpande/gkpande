//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    void dfs(int  node, int &end,int &minDia,vector<int> &visited,vector<pair<int,int>>graph[]){
        visited[node]=1;
        for(auto i:graph[node]){
            if(visited[i.first]==0){
                end=i.first;
                minDia=min(i.second,minDia);
                dfs(i.first,end,minDia,visited,graph);
            }
        }
    }
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        vector<vector<int>>ans;
        vector<vector<int>>arr(2,vector<int>(n+1,0));
        vector<pair<int,int>> graph[n+1];
        for(int i=0;i<p;i++){
            arr[1][a[i]]=1;
            arr[0][b[i]]=1;
            graph[a[i]].push_back({b[i],d[i]});
        }
        vector<int>visited(n+1,0);
        for(int i=1;i<=n;i++){
            if(arr[0][i]==0 && arr[1][i]==1 && visited[arr[0][i]]==0){
                int start=i;
                int minDia=INT_MAX;
                int end;
                dfs(start,end,minDia,visited,graph);
                vector<int>temp;
                temp.push_back(start);
                temp.push_back(end);
                temp.push_back(minDia);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends