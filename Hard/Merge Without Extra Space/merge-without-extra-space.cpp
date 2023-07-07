//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void swapElement(long long arr1[], long long arr2[], int left, int right){
            if(arr1[left]>arr2[right]){
                swap(arr1[left],arr2[right]);
            }
        }
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { //gap method.
             int size=n+m;//calculating total size.
             int gap=(size/2)+(size%2);//taking ceil value
             while(gap>0){
                 int left=0;
                 int right=left+gap;
                 while(right<size){
                     //arr1 arr2
                     if(left<n && right>=n){
                         swapElement(arr1,arr2,left,right-n);
                     }
                     //arr2 arr2
                     else if(left>=n && right>=n){
                         swapElement(arr2,arr2,left-n,right-n);
                     }
                     else{
                         swapElement(arr1,arr1,left,right);
                     }
                     left++;right++;
                 }
                 if(gap==1){
                     break;
                 }
                 gap=(gap/2)+(gap%2);
             }
        } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends