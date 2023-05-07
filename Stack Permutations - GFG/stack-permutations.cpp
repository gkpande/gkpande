//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        stack<int>s;
        int j=0;
        for(int i=0;i<N;i++){
            s.push(A[i]);
            if(s.top()==B[j]){
                while(!s.empty() && s.top()==B[j] && j<N){
                    s.pop();
                    j++;
                }
            }
        }
        if(!s.empty()){
            return 0;
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        Solution ob;
        cout<<ob.isStackPermutation(n,a,b)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends