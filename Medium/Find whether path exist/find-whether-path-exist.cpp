//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool solveBFS(vector<vector<int>>&grid,int i,int j,int n){
        queue<pair<int,int>>q;
        q.push({i,j});
        vector<vector<int>>visi(n,vector<int>(n,0));
        visi[i][j]=1;
        while(!q.empty()){
            auto f=q.front();
            i=f.first;
            j=f.second;
            q.pop();
            if(grid[i][j]==2){
                return true;
            }
            //up
            if(i-1>=0 && grid[i-1][j]!=0 && visi[i-1][j]==0){
                visi[i-1][j]=1;
                
                q.push({i-1,j});
            }
            //down
            if(i+1<n && grid[i+1][j]!=0 && visi[i+1][j]==0){
                visi[i+1][j]=1;
                q.push({i+1,j});
            }
            //right
            if(j+1<n && grid[i][j+1]!=0 && visi[i][j+1]==0){
                visi[i][j+1]=1;
                q.push({i,j+1});
            }
            //left
            if(j-1>=0 && grid[i][j-1]!=0 && visi[i][j-1]==0){
                visi[i][j-1]=1;
                q.push({i,j-1});
            }
            
            
        }
        return false;
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //find 1 in grid
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    bool ans=solveBFS(grid,i,j,n);
                    if(ans==true){
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends