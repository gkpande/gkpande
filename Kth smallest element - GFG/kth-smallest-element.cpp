//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int partition(int arr[],int l,int r){
        int pivote=arr[l];
        int j=l,i;
        for(i=l+1;i<=r;i++){
            if(arr[i]<=pivote){
                j++;
                swap(arr[j],arr[i]);
            }
        }
        swap(arr[l],arr[j]);
        return j;
    }
    void solve(int arr[],int l,int r,int k){
        int pi=partition(arr,l,r);
        if(pi==k-1){
            return;
        }
        if(pi<k-1){
            solve(arr,pi+1,r,k);
        }
        if(pi>k-1){
            solve(arr,l,pi-1,k);
        }
        
    }
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        solve(arr,l,r,k);
        return arr[k-1];
    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends