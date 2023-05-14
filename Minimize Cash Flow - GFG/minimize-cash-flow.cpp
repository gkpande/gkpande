//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        void minimunCashFlow(vector<vector<int>>&ans,vector<int>&amount,int n){
            //find min index and max index
            
            int maxi=0,mini=0;
            
            for(int i=1;i<n;i++ ){
                if(amount[i]<amount[mini]){
                    
                    mini=i;
                }
            }
            
            for(int i=1;i<n;i++ ){
                if(amount[i]>amount[maxi]){
                    
                    maxi=i;
                }
            }
            // cout<<maxi<<mini<<"--";
            if(amount[maxi]==0 && amount[mini]==0){
                return;
            }
            //find min in both maxC minD
            int x=min(-amount[mini],amount[maxi]);
            amount[mini] +=x;
            amount[maxi]-=x;
            // cout<<"x="<<x;
            ans[mini][maxi]=x;
            
            minimunCashFlow(ans,amount,n);
        }
        vector<vector<int>> minCashFlow(vector<vector<int>> &transaction, int n)
        {
            vector<vector<int>>ans(n,vector<int>(n,0));
            vector<int>amount(n,0);
            //create amount array
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    amount[i]+=(transaction[j][i]-transaction[i][j]);
                }
            }
            // for(int i=0;i<n;i++){
            //     cout<<amount[i]<<"/";
            // }
            minimunCashFlow(ans,amount,n);
            return ans;
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
        vector<vector<int>> g(n,vector<int> (n));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cin>>g[i][j];
        }
        Solution s;
        vector<vector<int>> r=s.minCashFlow(g,n);
        for(auto j:r)
        {
            for(auto i:j)
                cout<<i<<" ";
            cout<<endl;
        }
        // cout<<endl;
    }
    return 0;
}
// } Driver Code Ends