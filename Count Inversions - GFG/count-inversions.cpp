//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(long long arr[],long long left,long long mid,long long right,long long &countInver){
        long long ls=mid-left+1;
        long long rs=right-mid;
        long long arr1[ls];
        long long arr2[rs];
        for(long long i=0;i<ls;i++){
            arr1[i]=arr[left+i];
        }
        for(long long i=0;i<rs;i++){
            arr2[i]=arr[mid+1+i];
        }
        long long k=left,i=0,j=0;
        while(i<ls && j<rs){
            if(arr1[i]>arr2[j]){
                arr[k]=arr2[j];
                j++;k++;
                countInver +=ls-i;
            }
            else{
                arr[k]=arr1[i];
                i++;k++;
            }
        }
        while(i<ls){
            arr[k]=arr1[i];
            i++;k++;
        }
        while(j<rs){
            arr[k]=arr2[j];
            j++;k++;
        }
    }
    void mergeSort(long long arr[],long long left,long long right,long long &countInver){
        long long mid;
        if(left>=right){
            return;
        }
        mid=left+(right-left)/2;
        mergeSort(arr,left,mid,countInver);
        mergeSort(arr,mid+1,right,countInver);
        merge(arr,left,mid,right,countInver);
    }
    long long int inversionCount(long long arr[], long long N)
    {
       long long countInver=0;
       mergeSort(arr,0,N-1,countInver);
       return countInver;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends