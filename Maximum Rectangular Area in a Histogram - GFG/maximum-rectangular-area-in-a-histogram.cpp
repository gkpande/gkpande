//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //find next smaller array
    vector<long long> findNextSmaller(long long arr[],int n){
        stack<long long>st;
        st.push(-1);
        vector<long long>ans(n);
        for(int i=n-1;i>=0;i--){
            while(st.top()!=-1 && arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
                
            }
        
        return ans;
    }
    //find prev smaller array
    vector<long long> findPrevSmaller(long long arr[] ,int n){
        stack<long long>st;
        st.push(-1);
        vector<long long>ans(n);
        for(int i=0; i<n; i++){
            while(st.top()!=-1 && arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
                
        }
        
        return ans;
    }
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        vector<long long>nextSmaller(n);
        nextSmaller=findNextSmaller(arr,n);
        vector<long long>prevSmaller(n);
        prevSmaller=findPrevSmaller(arr,n);
        long long maxArea=LLONG_MIN;
        for(int i=0;i<n;i++){
            if(nextSmaller[i]==-1){
                nextSmaller[i]=n;
            }
            long long width=nextSmaller[i]-prevSmaller[i]-1;
            long long hieght=arr[i];
            long long newArea=width*hieght;
            maxArea=max(maxArea,newArea);
        }
        return maxArea;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends