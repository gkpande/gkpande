//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	   sort(arr,arr+n);
	   long long count=0;
	   for(int i=0;i<n;i++){
	       int l=i+1;
	       int h=n-1;
	       while(l<h){
	           if(arr[i]+arr[l]+arr[h]<sum){
	               count=count+h-l;
	               l++;
	           }
	           else{
	               h--;
	           }
	       }
	   }
	   return count;
	}
		 

};

//{ Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends