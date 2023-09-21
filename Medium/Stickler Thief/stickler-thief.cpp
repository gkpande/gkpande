//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int solveRec(int arr[],int n,int index){
        if(index>=n){
            return 0;
        }
        int ans1=arr[index]+solveRec(arr,n,index+2);
        int ans2=0+solveRec(arr,n,index+1);
        return max(ans1,ans2);
    }
    int solveMem(int arr[],int n,int index,vector<int> &dp){
        if(index>=n){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int ans1=arr[index]+solveMem(arr,n,index+2,dp);
        int ans2=0+solveMem(arr,n,index+1,dp);
        dp[index]=max(ans1,ans2);
        return dp[index];
    }
    int solveTab(int arr[],int n){
        vector<int>dp(n+1,0);
        dp[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            int curr=arr[i]+dp[i+2];
            int prev=0+dp[i+1];
            dp[i]=max(curr,prev);
        }
        
        return dp[0];
    }
    int solveSo(int arr[],int n){
       int incl=0;
       int excl=arr[0];
        
        for(int i=1;i<n;i++){
            incl=arr[i]+incl;
            excl=0+excl;
            int ans=max(incl,excl);
            incl=excl;
            excl=ans;
        }
        
        return excl;
    }
    int FindMaxSum(int arr[], int n)
    {
        // return solveRec(arr,n,0);
        //rec+mem
        // vector<int>dp(n,-1);
        // return solveMem(arr,n,0,dp);
        //tabulation method
        // return solveTab(arr,n);
        return solveSo(arr,n);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends