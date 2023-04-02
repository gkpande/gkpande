//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int t=0;
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2){
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
            if(l-1 >=0 && grid[k][l-1]==1 ){
                grid[k][l-1]=2;
                q.push({{k,l-1},t+1});
            }
            //right
            if(l+1 < col && grid[k][l+1]==1 ){
                grid[k][l+1]=2;
                q.push({{k,l+1},t+1});
            }
            //down
            if(k+1 < row && grid[k+1][l]==1 ){
                grid[k+1][l]=2;
                q.push({{k+1,l},t+1});
            }
            //up
            if(k-1>=0 && grid[k-1][l]==1 ){
                grid[k-1][l]=2;
                q.push({{k-1,l},t+1});
            }
        }
        
       for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return t;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends