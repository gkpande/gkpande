//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long int findMaxProduct(vector<int>&a, int n){
        if(n==1){
            return a[0];
        }
          long long int maxProd=1;
          long long int countZero=0;
          long long int countNeg=0;
          long long int maxNeg=INT_MIN;
          for(int i=0;i<n;i++){
              if(a[i]==0){
                  countZero++;
                  continue;
              }
              if(a[i]<0){
                  countNeg++;
                  maxNeg=max(maxNeg,1LL*a[i]);
              }
              maxProd =(maxProd*1LL*a[i])%1000000007;
          }
          if(countZero==n){
              return 0;
          }
          if(countZero==n-1 && countNeg>0){
              return 0;
          }
          if(countNeg & 1){
              return maxProd/maxNeg;
          }
          return maxProd;
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
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    long long int ans = ob.findMaxProduct(arr, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends