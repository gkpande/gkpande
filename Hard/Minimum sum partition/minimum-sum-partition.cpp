//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  int solveRec(int arr[],int n,int i,int s1,int s2)
  {
      if(i>=n){
          return abs(s1-s2);
      }
      //ith element include in set1;
      int take=solveRec(arr,n,i+1,s1+arr[i],s2);
      //include ith item in s2
      int notTake=solveRec(arr,n,i+1,s1,s2+arr[i]);
      return min(take,notTake);
  }
  int solveMem(int arr[],int n,int i,int sum,int totalSum,vector<vector<int>>&dp)
  {
      if(i>=n){
          return abs((totalSum-sum)-sum);
      }
      if(dp[i][sum]!=-1){
          return dp[i][sum];
      }
      //ith element include in set1;
      int take=solveMem(arr,n,i+1,sum+arr[i],totalSum,dp);
      //include ith item in s2
      int notTake=solveMem(arr,n,i+1,sum,totalSum,dp);
      dp[i][sum]=min(take,notTake);
      return dp[i][sum];
  }
	int minDifference(int arr[], int n)  { 
	   // return solveRec(arr,n,0,0,0);
	   //memorization
	   //find total sum
	   int totalSum=0;
	   for(int i=0;i<n;i++){
	       totalSum+=arr[i];
	   }
	   vector<vector<int>>dp(n,vector<int>(totalSum+1,-1));
	   return solveMem(arr,n,0,0,totalSum,dp);
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

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends