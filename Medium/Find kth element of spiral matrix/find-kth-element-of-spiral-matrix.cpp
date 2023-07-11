//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int matrix[MAX][MAX],int r,int c,int k)
    {
 		int n=r*c;
        int sr=0,er=r-1,sc=0,ec=c-1;
        while(n){
            for(int i=sc;i<=ec && n>0;i++){
                k--;
                if(k==0){
                    return matrix[sr][i];
                }
                
                n--;
            }
            sr++;ec--;
            for(int i=sr;i<=er && n>0;i++){
                k--;
                if(k==0){
                    return matrix[i][ec+1];
                }
                
                n--;
            }
            er--;
            for(int i=ec;i>=sc && n>0;i--){
                k--;
                if(k==0){
                    return matrix[er+1][i];
                }
                
                n--;
            }
            sc++;
            for(int i=er;i>=sr && n>0;i--){
                k--;
                if(k==0){
                    return matrix[i][sc-1];
                }
                
                n--;
            }
        }
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends