//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxSum(int N){
        vector<int>arr(N);
        int i=1,j=N,c=0;
        while(i<=j){
            if(c&1){
                arr[c]=j;
                j--;
            }else{
                arr[c]=i;
                i++;
                
            }
            c++;
        }
        int sum=0;
        for(int i=1;i<N;i++){
            sum=sum+abs(arr[i]-arr[i-1]);
        }
        sum=sum+abs(arr[N-1]-arr[0]);
        return sum-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.maxSum(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends