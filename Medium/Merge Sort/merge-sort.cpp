//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        int leftArr[m-l+1];
        int rightArr[r-m],k=0;
        //copy 1st l to m element in left array
        for(int i=l;i<=m;i++){
            leftArr[k]=arr[i];
            k++;
        }
        //copy right part in right array
        k=0;
        for(int j=m+1;j<=r;j++){
            rightArr[k]=arr[j];
            k++;
        }
        int size1=m-l+1,size2=r-m;
        int i=0,j=0;
        k=l;
        while(i<size1 && j< size2){
            if(leftArr[i]<rightArr[j]){
                arr[k]=leftArr[i];
                k++;i++;
            }else{
                arr[k]=rightArr[j];
                k++;j++;
            }
        }
        while(i<size1){
            arr[k]=leftArr[i];
            i++;k++;
        }
        while(j<size2){
            arr[k]=rightArr[j];
            k++;j++;
        }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l==r){
            return;
        }
        int mid=l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends