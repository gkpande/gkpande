//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // cout<<n;
        stack<int>st;
        for(int i=0;i<n;i++){
            st.push(i);
        }
        while(st.size()>1){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            if( M[a][b]==1){
                st.push(b);
            }
            else{
                st.push(a);
            }
            
        }
        int cand=st.top();
        int zerocount=0;
        for(int i=0;i<n;i++){
            if(M[cand][i]==0){
                zerocount++;
            }
        }
        int rowcheck=0;
        if(zerocount==n){
            rowcheck=1;
        }
        int onecount=0;
        for(int i=0;i<n;i++){
            if(M[i][cand]==1){
                onecount++;
            }
        }
        int colcheck=0;
        if(onecount==n-1){
            colcheck=1;
        }
        if(rowcheck==1 && colcheck==1){
            return cand;
        }
        else{
            return -1;
        }
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends