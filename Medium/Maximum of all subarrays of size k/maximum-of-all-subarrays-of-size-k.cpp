//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    void bruitForce(int *arr, int n, int k,vector<int>&ans){
        for(int i=0;i<=n-k;i++){
            int maxElement=INT_MIN;
            for(int j=i;j<i+k;j++){
                maxElement=max(maxElement,arr[j]);
            }
            ans.push_back(maxElement);
        }
    }
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int>ans;
        // bruitForce(arr,n,k,ans);
        //effecient approach
        deque<int>dq;
        //process 1st window
        int i;
        for(i=0;i<k;i++){
            while(!dq.empty() && arr[i]>=arr[dq.back()] ){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        
        for( ;i<n;i++){
            ans.push_back(arr[dq.front()]);
            //if front element is not lying in window.
            while(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }
            while(!dq.empty() && arr[i]>=arr[dq.back()] ){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(arr[dq.front()]);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends