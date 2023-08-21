//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        int arr[2][8]={{-1,0,1,1,1,0,-1,-1},{-1,-1,-1,0,1,1,1,0}};
        int count1s=0;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    int countZero=0;
                    for(int k=0;k<8;k++){
                        if((i+arr[0][k]>=0 && i+arr[0][k]<n) &&(j+arr[1][k]>=0 && j+arr[1][k]<m) && matrix[i+arr[0][k]][j+arr[1][k]]==0){
                            countZero++;
                        }
                    }
                    if(countZero!=0 && countZero%2==0){
                        count1s++;
                    }
                }
            }
        }
        return count1s;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends