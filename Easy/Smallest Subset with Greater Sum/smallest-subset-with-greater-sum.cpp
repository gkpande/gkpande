//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int minSubset(vector<int> &Arr,int n){
        sort(Arr.begin(),Arr.end());
        long long sum=0;
        for(int i=0;i<n;i++){
            sum = sum+ 1ll*Arr[i];
        }
        long long sum1=0;
        int i=n-1;
        while(i>=0){
            sum1 = sum1+1ll*Arr[i];
            sum =sum-1ll*Arr[i];
            if(sum1>sum){
                return n-i;
            }
            i--;
        }
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        cout<<ob.minSubset(Arr,N)<<endl;
    }
    return 0;
}
// } Driver Code Ends