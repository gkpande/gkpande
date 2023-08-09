//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
void approach1(int arr[],int n){
    // +ve element at even position and -ve element at odd position
	    //check for each elelemnt if its at outplace
	    for(int i=0;i<n;i++){
	        if(arr[i]<0 && i%2==0){
	            //find the 1st positive element
	            int j=i+1;
	            while(j<n && arr[j]<0){
	                j++;
	            }
	            //shift the array
	            int temp=arr[j];
	            j=j-1;
	            while(j>=i){
	                arr[j+1]=arr[j];
	            }
	            arr[i]=temp;
	        }
	        else if(arr[i]>=0 && i%2==1){
	            //find the -ve element
	            int j=i+1;
	            while(j<n && arr[j]>=0){
	                j++;
	            }
	            //shift the array
	            int temp=arr[j];
	            j=j-1;
	            while(j>=i){
	                arr[j+1]=arr[j];
	            }
	            arr[i]=temp;
	        }
	    }
}
void approach2(int arr[],int n){
    // 
    int pos=0,neg=0;
    for(int i=0;i<n;i++){
        if(arr[i]>=0){
            pos++;
        }else{
            neg++;
        }
    }
    int a[pos];
    int b[neg];
    int i=0,j=0;
    for(int k=0;k<n;k++){
        if(arr[k]>=0){
            a[i]=arr[k];
            i++;
        }else{
            b[j]=arr[k];
            j++;
        }
    }
    
    int k=0;
    i=0;j=0;
    while(i<pos && j<neg){
        if(k%2==0){
            arr[k]=a[i];
            i++;
        }else{
            arr[k]=b[j];
            j++;
        }
        k++;
    }
    while(i<pos){
        arr[k]=a[i];
        i++;k++;
    }
    while(j<neg){
        arr[k]=b[j];
        j++;
        k++;
    }
}
	void rearrange(int arr[], int n) {
	   // approach1(arr,n);//time O(n^2) space O(1);
	    approach2(arr,n);//time O(n) sapce O(n);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends