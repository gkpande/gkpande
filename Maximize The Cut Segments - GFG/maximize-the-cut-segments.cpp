//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int solveRec(int n,int x,int y,int z){
        if(n==0){
            return 0;// n=0 means rod have no length so where to cut.
        }
        if(n<0){
            return INT_MIN;
        }
        int a=solveRec(n-x,x,y,z)+1;
        int b=solveRec(n-y,x,y,z)+1;
        int c=solveRec(n-z,x,y,z)+1;
        return max(a,max(b,c));
    }
    int solveMem(int n,int x,int y,int z,vector<int>&dp){
        dp[0]=0;
        int a=INT_MIN,b=INT_MIN,c=INT_MIN;
        for(int i=1;i<=n;i++){
            if(i-x>=0){
                 a=dp[i-x]+1;
            }
            if(i-y>=0){
                 b=dp[i-y]+1;
            }
            if(i-z>=0){
                 c=dp[i-z]+1;
            }
            dp[i]=max(a,max(b,c));
            
        }
        if(dp[n]<0){
            return 0;
        }
        return dp[n];
        
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //recursive solution
        // return solveRec(n,x,y,z);
        //recursive + memorization
        vector<int>dp(n+1,-1);
        return solveMem(n,x,y,z,dp);
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends