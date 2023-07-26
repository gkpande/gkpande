//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    long long countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        //approach 2 window method
        int start=0;
        long long count=0;
        long long p=1;
        for(int end=0;end<n;end++){
            p =p*a[end];
            if(p<k){
                count=count+1ll* (1+end-start);
            }
            if(p>=k){
                while(start<=end && p>=k){
                    
                    p=p/a[start];
                    start++;
                }
                if(start<=end){
                    count=count+1ll* (1+end-start);
                }
            }
            
            
            
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends