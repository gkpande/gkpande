//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		int firstbs(int arr[],int x,int i,int j){
		    int first=0;
		    while(i<=j){
		        int mid= (i+j)/2;
		        if(arr[mid]==x){
		            first=mid+1;
		        }
		        if(arr[mid]==x || arr[mid]>x){
		            j=mid-1;
		        }
		        else{
		            i=mid+1;
		        }
		            
		    }
		    
		    return first;
		}
		int secondbs(int arr[],int x,int i,int j){
		    int second=0;
		    while(i<=j){
		        int mid= (i+j)/2;
		        if(arr[mid]==x){
		            second=mid+1;
		        }
		        if(arr[mid]==x || arr[mid]<x){
		            i=mid+1;
		        }
		        else{
		            j=mid-1;
		        }
		            
		    }
		    
		    return second;
		}
	int count(int arr[], int n, int x) {
	    int i=0;
	    int j=n-1;
	    int firstOcc=firstbs(arr,x,0,n-1);
	    
	    int secondOcc=secondbs(arr,x,0,n-1);
	   // cout<<firstOcc<<secondOcc;
	   if(firstOcc==0 && secondOcc==0){
	       return 0;
	   }
	    return secondOcc-firstOcc+1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends