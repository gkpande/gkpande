//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod=1003;
    int solveRec(string s,int i,int j,int isTrue){
        if(i>j){
            return 0;
        }
        if(i==j){
            if(isTrue){
                return s[i]=='T';
            }
            else{
                return s[i]=='F';
            }
        }
        int ways=0;
        for(int ind=i+1;ind<=j-1;ind+=2){
            int lt=solveRec(s,i,ind-1,1);
            int lf=solveRec(s,i,ind-1,0);
            int rt=solveRec(s,ind+1,j,1);
            int rf=solveRec(s,ind+1,j,0);
            
            if(s[ind]=='&'){
                if(isTrue){
                    ways =(ways+(lt*rt)%mod)%mod;
                }else{
                    ways=(ways+(lt*rf)%mod+(rt*lf)%mod+(lf*rf)%mod)%mod;
                }
            }
            else if(s[ind]=='|'){
                if(isTrue){
                    ways=(ways+(lt*rf)%mod+(lt*rt)%mod+(rt*lf)%mod)%mod;
                }
                else{
                    ways=(ways+(lf*rf)%mod)%mod;
                }
            }
            else if(s[ind]=='^'){
                if(isTrue){
                    ways=(ways+(lt*rf)%mod+(rt*lf)%mod)%mod;
                }
                else{
                    ways=(ways+(lf*rf)%mod+(lt*rt)%mod)%mod;
                }
            }
        }
        return ways;
    }
    int solveMem(string s,int i,int j,int isTrue,vector<vector<vector<int>>>&dp){
        if(i>j){
            return 0;
        }
        if(i==j){
            if(isTrue){
                return s[i]=='T';
            }
            else{
                return s[i]=='F';
            }
        }
        if(dp[i][j][isTrue]!=-1){
            return dp[i][j][isTrue]; 
        }
        int ways=0;
        for(int ind=i+1;ind<=j-1;ind+=2){
            int lt=solveMem(s,i,ind-1,1,dp);
            int lf=solveMem(s,i,ind-1,0,dp);
            int rt=solveMem(s,ind+1,j,1,dp);
            int rf=solveMem(s,ind+1,j,0,dp);
            
            if(s[ind]=='&'){
                if(isTrue){
                    ways =(ways+(lt*rt)%mod)%mod;
                }else{
                    ways=(ways+(lt*rf)%mod+(rt*lf)%mod+(lf*rf)%mod)%mod;
                }
            }
            else if(s[ind]=='|'){
                if(isTrue){
                    ways=(ways+(lt*rf)%mod+(lt*rt)%mod+(rt*lf)%mod)%mod;
                }
                else{
                    ways=(ways+(lf*rf)%mod)%mod;
                }
            }
            else if(s[ind]=='^'){
                if(isTrue){
                    ways=(ways+(lt*rf)%mod+(rt*lf)%mod)%mod;
                }
                else{
                    ways=(ways+(lf*rf)%mod+(lt*rt)%mod)%mod;
                }
            }
        }
        dp[i][j][isTrue]=ways;
        return dp[i][j][isTrue];
    }
    int countWays(int N, string S){
        // return solveRec(S,0,N-1,1);
        vector<vector<vector<int>>>dp(N,vector<vector<int>>(N,vector<int>(2,-1)));
        return solveMem(S,0,N-1,1,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends