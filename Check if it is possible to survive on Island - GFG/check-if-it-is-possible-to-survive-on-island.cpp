//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
        //S no of days to survive
        //N amt of food you can get daily
        int TotalFood=S*M;  //total food require.
        int ans;
        if(TotalFood%N==0){
            ans =TotalFood/N;
        }
        else{
            ans =TotalFood/N+1;
        }
        //total days you can buy food if exclude sunday
        int buyingDays=S-(S/7);
        if(ans<=buyingDays){
            return ans;
        }
        else{
            return -1;
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends