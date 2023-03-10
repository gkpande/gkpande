//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool isvalid(int sr,int sc,vector<vector<int>>&image,int color1,int color,int n,int m){
        if((sr>=0 && sr<n) && (sc>=0 && sc< m) &&  image[sr][sc]==color1 && image[sr][sc]!=color){
            return true;
        }

        return false;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n=image.size();
        int m=image[0].size();
        // vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        
        int color=newColor;
        q.push({sr,sc});
       
        int color1=image[sr][sc];
        image[sr][sc]=color;
        while(!q.empty()){
            pair<int,int>p=q.front();
            int sr1=p.first;
            int sc1=p.second;
            q.pop();
            
            
            //up
            if(isvalid(sr1-1,sc1,image,color1,color,n, m)){
                q.push({sr1-1,sc1});
                image[sr1-1][sc1]=color;
            }
            //down
            if(isvalid(sr1+1,sc1,image,color1,color,n, m)){
                q.push({sr1+1,sc1});
                image[sr1+1][sc1]=color;
            }
            //left
            if(isvalid(sr1,sc1-1,image,color1,color,n, m)){
                q.push({sr1,sc1-1});
                image[sr1][sc1-1]=color;
            }
            //right
            if(isvalid(sr1,sc1+1,image,color1,color,n, m)){
                q.push({sr1,sc1+1});
                image[sr1][sc1+1]=color;
            }

        }

        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends