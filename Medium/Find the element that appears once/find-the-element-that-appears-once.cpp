//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int search(int A[], int N){
	    //find the mid element check mid is repeating or not 
	    //if mid is not repeating then check on which side mid is repeating
	    //check single element is present on which side of element that side having odd number of 
	    //element
	    if(N%2==0){
	        return 0;
	    }
	    int left=0,right =N-1;
	    while(left<right){
	        int mid=left+(right-left)/2;
	        if((mid>0 && A[mid-1]==A[mid])){
	            if((mid-1-left)%2==0){
	                left=mid+1;
	            }
	            else{
	                right=mid-2;
	            }
	        } 
	        else if(mid<N-1 && A[mid+1]==A[mid]){
	            if((right-mid-1)%2==0){
	                right=mid-1;
	            }else{
	                left=mid+2;
	            }
	        }
	        else{
	            return A[mid];
	        }
	    
	    }
	    return A[left];
	}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}

// } Driver Code Ends