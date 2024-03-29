//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

const int mod=1e9+7;
class Solution{
    public:

    int Maximize(int a[],int n)
    {
        sort(a,a+n);
        long sum=0;
        int mod=1e9+7;
        for(long i=0;i<n;i++)
        {
            sum=sum+(a[i]*i);
        }
        return (sum%mod);
    }
};

//{ Driver Code Starts.
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.Maximize(a,n)<<endl;
    }
}
// } Driver Code Ends