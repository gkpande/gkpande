//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int solveSo(int n,vector<long long>&prices,int fee){
      int curr[2]={0,0};
      int prev[2]={0,0};
      
      for(int i=n-1;i>=0;i--){
          for(int j=0;j<=1;j++){
                int take=0;
                int notTake;
                if(j==1){
                    take=-prices[i]+prev[0];
                    notTake=0+prev[1];
                
                }
                else{
                    take=prices[i]-fee+prev[1];
                    notTake=0+prev[0];
          
                }
                curr[j]=max(take,notTake);
            }
            prev[0]=curr[0];
            prev[1]=curr[1];
        }
      
      return  prev[1];
      
  }
    long long maximumProfit(vector<long long>&prices, int n, int fee) {
        return solveSo(n,prices,fee);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        int fee; cin>>fee;
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n, fee)<<"\n";
    }
    return 0;
}
// } Driver Code Ends