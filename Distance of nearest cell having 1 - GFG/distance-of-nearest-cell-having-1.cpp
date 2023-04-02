//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int row=grid.size();
	    int col=grid[0].size();
	    int t=0;
	    vector<vector<int>>visited(row,vector<int>(col,0));
	    vector<vector<int>>ans(row,vector<int>(col,0));
	    queue<pair<pair<int,int>,int>>q;
	    for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    ans[i][j]=0;
                    visited[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty()){
            pair<pair<int,int>,int>p=q.front();
            q.pop();
            int k=p.first.first;
            int l=p.first.second;
            t=p.second;
            //left
            if(l-1 >=0 &&visited[k][l-1]==0 && grid[k][l-1]==0 ){
                ans[k][l-1]=t+1;
                visited[k][l-1]=1;
                q.push({{k,l-1},t+1});
            }
            //right
            if(l+1 < col && visited[k][l+1]==0 && grid[k][l+1]==0 ){
                ans[k][l+1]=t+1;
                visited[k][l+1]=1;
                q.push({{k,l+1},t+1});
            }
            //down
            if(k+1 < row && visited[k+1][l]==0 && grid[k+1][l]==0 ){
                ans[k+1][l]=t+1;
                visited[k+1][l]=1;
                q.push({{k+1,l},t+1});
            }
            //up
            if(k-1>=0 && visited[k-1][l]==0 && grid[k-1][l]==0 ){
                ans[k-1][l]=t+1;
                visited[k-1][l]=1;
                q.push({{k-1,l},t+1});
            }
        }
	    
	   return ans; 
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends