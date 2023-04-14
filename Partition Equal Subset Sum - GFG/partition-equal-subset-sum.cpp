//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int solveRec(int N,int arr[],int sum,int index){
    if(sum == 0){
        return 1;
    }
    if(sum<0){
        return 0;
    }
    if(index>=N){
        return 0;
    }
    int incl=solveRec(N,arr,sum-arr[index],index+1);
    int excl=solveRec(N,arr,sum-0,index+1);
    return incl||excl;
}
int solveMem(int N,int arr[],int sum,vector<vector<int>>&dp,int index){
    if(sum == 0){
        return 1;
    }
    if(sum<0){
        return 0;
    }
    if(index>=N){
        return 0;
    }
    if(dp[index][sum]!=-1){
        return dp[index][sum];
    }
    int incl=solveMem(N,arr,sum-arr[index],dp,index+1);
    int excl=solveMem(N,arr,sum-0,dp,index+1);
    dp[index][sum]=incl||excl;
    return dp[index][sum];
}
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++){
            sum +=arr[i];
        }
        if(sum%2==1){
            return 0;
        }
        else{
            sum=sum/2;
        }
    //   return solveRec(N,arr,sum,0);
    //rec+mem
    vector<vector<int>>dp(N,vector<int>(sum+1,-1));
   
    return  solveMem(N,arr,sum,dp,0);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends