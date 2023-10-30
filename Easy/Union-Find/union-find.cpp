//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:


    int findParent(int node,int par[]){
        if(node==par[node]){
            return node;
        }
        return par[node]=findParent(par[node],par);
    }    
    //Function to merge two nodes a and b.
    void union_( int a, int b, int par[], int rank1[]) 
    {
        int ulp_u=findParent(a,par);
        int ulp_v=findParent(b,par);
        if(ulp_u==ulp_v){
            return;
        }
        int rank_ulp_u=rank1[ulp_v];
        int rank_ulp_v=rank1[ulp_u];
        if(rank_ulp_u<rank_ulp_v){
            par[ulp_u]=ulp_v;
        
        }
        else if(rank_ulp_v<rank_ulp_u){
            par[ulp_v]=ulp_u;
            
        }
        else{
            par[ulp_u]=ulp_v;
            rank1[ulp_v]++;
        }
    }
    
    //Function to check whether 2 nodes are connected or not.
    bool isConnected(int a,int b, int par[], int rank1[])
    {
        int ulp_u=findParent(a,par);
        int ulp_v=findParent(b,par);
        if(ulp_u==ulp_v){
            return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    //taking number of testcases
    int t;
    cin>>t;
    while(t--) {
        
        //taking number of elements
        int n;
        cin>>n;
        
        
        int par[n+1];
        int rank1[n+1];

        //initializing the parent and
        //the rank array
        for(int i=1; i<=n; i++) {
            par[i] = i;
            rank1[i] = 1;
    }
    
    //taking number of queries
    Solution obj;
    int q;
    cin>>q;
    while(q--) {    
        int a,b;
        char c;
        cin>>c>>a>>b;
        
        //if query type is 'U'
        //then calling union_ method
        if(c=='U')
        {
            obj.union_(a,b, par, rank1);
        }
        else//else calling isConnected() method
        cout<<obj.isConnected(a,b, par, rank1)<<endl;
    }
    }
    return 0;
}

// } Driver Code Ends