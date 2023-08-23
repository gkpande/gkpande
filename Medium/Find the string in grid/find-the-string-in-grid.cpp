//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    vector<vector<int>> ans;
        int n = grid.size();
        int m = grid[0].size();
    
        int l = word.length();
    
        int row[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int col[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == word[0]) {
                    for (int dir = 0; dir < 8; dir++) {
                        int r = i + row[dir];
                        int c = j + col[dir];
                        int k;
    
                        for (k = 1; k < l; k++) {
                            if (r >= n || r < 0 || c >= m || c < 0)
                                break;//outofrange so no need to search in this dir again
    
                            if (grid[r][c] != word[k])
                                break;//same same no need to check already nahi milega w
    
                            r += row[dir];
                            c += col[dir];
                        }
    
                        if (k == l) { //mil gya pura word
                            ans.push_back({i, j});//starting point push
                            break;  // Once found, no need to check in this direction
                        }
                    }
                }
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
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends