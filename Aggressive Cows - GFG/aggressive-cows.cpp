//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool isPossible(vector<int>&stalls,int mini,int n,int k){
        int countCow=1;
        int cowPos=0;
        for(int i=1;i<n;i++){
            if(stalls[i]-stalls[cowPos]>=mini){
                countCow++;
                cowPos=i;
            }
            if(countCow==k){
                return true;
            }
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        //find the search space
        int s=1;   //minimum distance will be 1
        int e=stalls[n-1]-stalls[0]; // maximum distance.
        int ans=-1;
        while(s<=e){
            int mini=s+(e-s)/2;  //let us it is minimum distance.
            if(isPossible(stalls,mini,n,k)){
                //go for right.
                ans=mini;
                s=mini+1;
            }
            else{
                e=mini-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends