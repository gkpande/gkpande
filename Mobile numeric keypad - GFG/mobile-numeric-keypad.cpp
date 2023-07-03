//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{


	public:
	long long solveRec(int n,char arr[4][3],int r,int c, long long &count){
	    if(n==1){
	        
	        return 1;
	    }
	    long long a=0,b=0,p=0,d=0,q=0;
	    //current
	    q=solveRec(n-1,arr,r,c,count);
	    //left
	    if(c-1>=0 && arr[r][c-1]!='*'){
	        a=solveRec(n-1,arr,r,c-1,count);
	    }
	    //right
	    if(c+1<3 && arr[r][c+1]!='#'){
	       b=solveRec(n-1,arr,r,c+1,count);
	    }
	    //up
	    if(r-1>=0){
	        p=solveRec(n-1,arr,r-1,c,count);
	    }
	    //down
	    if(r+1<4 && arr[r+1][c]!='*' && arr[r+1][c]!='#'){
	       d= solveRec(n-1,arr,r+1,c,count);
	    }
	    return q+a+b+p+d;
	}
	
	long long solveMem(int n,int arr[4][3],int r,int c, vector<vector<long long>>&dp){
	    if(n==1){
	        
	        return 1;
	    }
	    if(dp[arr[r][c]][n]!=-1){
	        return dp[arr[r][c]][n];
	    }
	    long long cu=0,l=0,ro=0,u=0,d=0;
	    //current
	    cu=solveMem(n-1,arr,r,c,dp);
	    //left
	    if(c-1>=0 && arr[r][c-1]!=-1){
	        l=solveMem(n-1,arr,r,c-1,dp);
	    }
	    //right
	    if(c+1<3 && arr[r][c+1]!=-1){
	       ro=solveMem(n-1,arr,r,c+1,dp);
	    }
	    //up
	    if(r-1>=0){
	        u=solveMem(n-1,arr,r-1,c,dp);
	    }
	    //down
	    if(r+1<4 && arr[r+1][c]!=-1 ){
	       d= solveMem(n-1,arr,r+1,c,dp);
	    }
	    dp[arr[r][c]][n]=cu+l+ro+u+d;
	    return dp[arr[r][c]][n];
	}
	long long getCount(int N)
	{
	    int arr[4][3]={{1,2,3},
	                    {4,5,6},
	                    {7,8,9},
	                    {-1,0,-1}};
	   long long count=0;
	                    
	   //for(int i=0;i<4;i++){
	   //    for(int j=0;j<3;j++){
	   //        if(arr[i][j]!='*' && arr[i][j]!='#'){
	   //            count+=solveRec(N,arr,i,j,count);
	   //        }
	   //    }
	   //}
	   //memorization
	   vector<vector<long long>>dp(10,vector<long long>(N+1,-1));
	   for(int i=0;i<4;i++){
	       for(int j=0;j<3;j++){
	           if(arr[i][j]!=-1){
	               count+=solveMem(N,arr,i,j,dp);
	           }
	       }
	   }
	   return count;
	    
	}


};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends