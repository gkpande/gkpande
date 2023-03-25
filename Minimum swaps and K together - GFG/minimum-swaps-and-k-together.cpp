//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
       int swap=0;
       int minSwap;
       //find out window size
       int wSize=0;
       for(int i=0;i<n;i++){
           if(arr[i]<=k){
               wSize++;
           }
       }
       //process 1st window to get number of swap required
       for(int i=0;i<wSize;i++){
           if(arr[i]>k){
               swap++;
           }
       }
       minSwap=swap;
       //now exclude 1st element from window and include one element in window
       int i=0;
       int j=wSize;
       while(j<n){
           if(arr[i]>k){
               swap--;
           }
           if(arr[j]>k){
               swap++;
           }
           minSwap=min(minSwap,swap);
           i++;
           j++;
       }
       return minSwap;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends