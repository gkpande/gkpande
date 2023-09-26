//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        vector<vector<int>>ans;
        //sort the array
        sort(arr.begin(),arr.end());
        //use two loop and two ptr
        int n=arr.size();
        for(int i=0;i<n-3;i++){ //i is running till n-3 because we need another 3 number
            for(int j=i+1;j<n-2;j++){//j is running till n-2 because we need another 2 number
                int sum =arr[i]+arr[j];//sum=a+b
                int remainSum=k-sum;
                int l=j+1; //i=a,j=b,l=c,h=d 
                int h=n-1;
                while(l<h){
                    if(arr[l]+arr[h]==remainSum){
                        vector<int>tans;
                        tans.push_back(arr[i]);
                        tans.push_back(arr[j]);
                        tans.push_back(arr[l]);
                        tans.push_back(arr[h]);
                        ans.push_back(tans);
                        l++;
                        while(arr[l]==arr[l-1]){
                            l++;
                        }
                        h--;
                        while(arr[h]==arr[h+1]){
                            h--;
                        }
                    }
                    else if(arr[l]+arr[h]<remainSum){
                        l++;
                    }
                    
                    else{
                        h--;
                    }
                }
                j++;
                while(arr[j]==arr[j-1]){
                        j++;
                }
                j--;
            }
            i++;
                while(arr[i]==arr[i-1]){
                        i++;
                }
                i--;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends