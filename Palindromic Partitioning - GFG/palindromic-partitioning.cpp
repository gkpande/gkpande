//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int palindrom(int i,int j,string &str){
    while(i<=j){
        if(str[i]!=str[j]){
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}
int solveRec(string &str ,int i,int n){
    if(i==n){
        return 0;
    }
    int minPart=INT_MAX;
    for(int j=i;j<n;j++){
        if(palindrom(i,j,str)){
            int cost=1+solveRec(str,j+1,n);
            minPart=min(minPart,cost);
        }
    }
    return minPart;
}
int solveMem(string &str ,int i,int n,vector<int>&dp){
    if(i==n){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int minPart=INT_MAX;
    for(int j=i;j<n;j++){
        if(palindrom(i,j,str)){
            int cost=1+solveMem(str,j+1,n,dp);
            minPart=min(minPart,cost);
        }
    }
    dp[i]=minPart;
    return dp[i];
}
    int palindromicPartition(string str)
    {
        int n=str.size();
        // return solveRec(str,0,n)-1;
        //memorization
        vector<int>dp(n,-1);
        return solveMem(str,0,n,dp)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends