//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        int fmax=INT_MIN;
        int smax=INT_MIN;
        string fStr="";
        string sStr="";
        for(auto it:mp){
            if(it.second>fmax){
                smax=fmax;
                fmax=it.second;
                sStr=fStr;
                fStr=it.first;
            }
            else if(it.second>smax){
                smax=it.second;
                sStr=it.first;
            }
        }
        // cout<<sStr;
        return sStr;
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
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends