//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	  
	   priority_queue<int,vector<int>,greater<int>>minpq;
	   for(int i=n-1;i>=n-k;i--){
	       minpq.push(arr[i]);
	   }
	   for(int i=n-k-1;i>=0;i--){
	       if(arr[i]>=minpq.top()){
	           minpq.pop();
	           minpq.push(arr[i]);
	       }
	   }
	    vector<int>ans(minpq.size());
	    int i=minpq.size()-1;
	   while(!minpq.empty()){
	       ans[i]=minpq.top();
	       minpq.pop();
	       i--;
	   }
	   return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends