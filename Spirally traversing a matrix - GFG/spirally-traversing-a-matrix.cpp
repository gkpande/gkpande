//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int>ans;
        int n=r*c;
        int sr=0,er=r-1,sc=0,ec=c-1;
        while(n){
            for(int i=sc;i<=ec && n>0;i++){
                ans.push_back(matrix[sr][i]);
                n--;
            }
            sr++;ec--;
            for(int i=sr;i<=er && n>0;i++){
                ans.push_back(matrix[i][ec+1]);
                n--;
            }
            er--;
            for(int i=ec;i>=sc && n>0;i--){
                ans.push_back(matrix[er+1][i]);
                n--;
            }
            sc++;
            for(int i=er;i>=sr && n>0;i--){
                ans.push_back(matrix[i][sc-1]);
                n--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends