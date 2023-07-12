//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        int len=INT_MAX;
        string ans="";
        for(int i=0;i<N;i++){
            if(arr[i].length()<len){
                len=arr[i].length();
            }
        }
        for(int i=0;i<len;i++){
            for(int j=1;j<N;j++){
                if(arr[j][i]!=arr[j-1][i]){
                    if(ans.length()==0){
                        return "-1";
                    }
                    else
                       return ans;
                }
            }
            ans +=arr[0][i];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends