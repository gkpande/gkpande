//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
void maxHeapify(vector<int>&arr,int i,int n){
    
        int largest=i;
        int leftIndex=2*i+1;
        int rightIndex=2*i+2;
        if(leftIndex<n && arr[leftIndex]>arr[largest]){
            largest=leftIndex;
                
        }
        if(rightIndex<n && arr[rightIndex]>arr[largest]){
            largest=rightIndex;
        }
        if (largest != i) {
            swap(arr[i], arr[largest]);
            maxHeapify(arr, largest, n);
        }
}
    void convertMinToMaxHeap(vector<int> &arr, int N){
        //start from last right most internal node to upwords
        //call maxheapify
        int i= (N-1)/2;
        while(i>=0){
            maxHeapify(arr, i, N);
            i--;
        }    

    }
    
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends