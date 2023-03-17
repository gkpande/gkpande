//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool isPossible(int mid,int A[],int N, int M){
        
        int stuCount=1;
        int sumPages=0; //number of pages to each student.
        for(int i=0;i<N;i++){
            if(sumPages+A[i]<=mid){
                sumPages+=A[i];
            }
            else{
                stuCount++;
                if(stuCount>M || A[i]>mid){
                    return false;
                }
                
                sumPages =A[i];
            }
        }
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(M>N){
            return -1;
        }
        //find search space
        int s=0;//minimum num of page s can be assign
        int e=0; //maximum pages can be assign.
        int ans=-1;
        for(int i=0;i<N;i++){
            e=e+A[i];
        }
        while(s<=e){
            int mid= s+(e-s)/2;
            if(isPossible(mid,A,N,M)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
    
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends