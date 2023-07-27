//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// User function Template for C++

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int ans=0;
        //create a row array
        if(n==1){
            for(int i=0;i<m;i++){
                if(mat[0][i]==1){
                    return 1;
                }
            }
            return 0;
        }
        if(m==1){
            for(int i=0;i<n;i++){
                if(mat[i][0]==1){
                    return 1;
                }
            }
            return 0;
        }
        vector<int>row(mat[0]);
        vector<int>curr(m);
        for(int i=1;i<n;i++){
            curr[0]=mat[i][0];
            for(int j=1;j<m;j++){
                if(mat[i][j]==0){
                    curr[j]=0;
                }else{
                    int temp=min(curr[j-1],row[j-1]);
                    temp=min(temp,row[j])+1;
                    curr[j]=temp;
                    ans=max(ans,temp);
                    
                }
            }
            
            row=curr;
            
        }
        
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends