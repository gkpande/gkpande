//{ Driver Code Starts
// C++ implementation of For each element in 1st 
// array count elements less than or equal to it
// in 2nd array
#include <bits/stdc++.h>
 
using namespace std;


// } Driver Code Ends
// function to count for each element in 1st array,
// elements less than or equal to it in 2nd array
class Solution{
  public:
    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], 
                                 int m, int n)
    {
        int freqArr[100000]={0};
        //strore frequency of each element of arr2
        for(int i=0;i<n;i++){
            freqArr[arr2[i]]++;
        }
        int prefixSum[100000];
        //prefix array will store 
        prefixSum[0]=freqArr[0];
        for(int i=1;i<100000;i++){
            prefixSum[i]=prefixSum[i-1]+freqArr[i];
        }
        vector<int>ans;
        for(int i=0;i<m;i++){
            ans.push_back(prefixSum[arr1[i]]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        int arr1[m],arr2[n];
        for(int i=0;i<m;i++)
        cin>>arr1[i];
        for(int j=0;j<n;j++)
        cin>>arr2[j];
        Solution obj;
        vector <int> res = obj.countEleLessThanOrEqual(arr1, arr2, m, n);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends