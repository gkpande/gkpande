//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        
        
        vector<int>nextSmaller(n+1,n);
        
        stack<int>st;
        //find next smaller index of each element
        for(int i=n-1;i>=0;i--){
            
                while(!st.empty() && arr[st.top()]>=arr[i]){
                    st.pop();
                }
                if(!st.empty() && arr[st.top()]<arr[i]){
                    nextSmaller[i]=st.top();
                }
                st.push(i);
            }
            //empty the stack
            while(!st.empty()){
                st.pop();
            }
            // find the previous smaller element of each index
            vector<int>prevSmaller(n+1,-1);
            for(int i=0;i<n;i++){
                while(!st.empty() && arr[st.top()]>=arr[i]){
                    st.pop();
                }
                if(!st.empty() && arr[st.top()<arr[i]]){
                    prevSmaller[i]=st.top();
                }
                st.push(i);
            }
            //create ans
            vector<int>ans(n+1,0);
            for (int i = 0; i < n; i++) {
                // length of the interval
                int len = nextSmaller[i] - prevSmaller[i] - 1;
 
                // arr[i] is a possible answer for this length
                // 'len' interval, check if arr[i] is more than
                // max for 'len'
                ans[len] = max(ans[len], arr[i]);
            }
            // Some entries in ans[] may not be filled yet. Fill
            // them by taking values from right side of ans[]
            for (int i = n - 1; i >= 1; i--){
                ans[i] = max(ans[i], ans[i + 1]);
            }
                
            vector<int>fans(n,0);
            // Print the result
            for (int i = 1; i <= n; i++)
            {
                fans[i-1]=ans[i];
            }
            return fans;

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends