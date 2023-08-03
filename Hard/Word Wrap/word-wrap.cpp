//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

int dp[500][2000];

class Solution {
public:

    int solve(int ind, vector<int> &nums, int remSpaces, int k) {
        if(ind >= nums.size()) {
            return 0;
        }
        if(dp[ind][remSpaces] != -1) {
            return dp[ind][remSpaces];
        }
        int ans;
        // If space is not there then we have to keep the word
        // in the next line
        if(nums[ind] > remSpaces) {
            ans = (remSpaces+1)*(remSpaces+1) + 
            solve(ind+1, nums, k-nums[ind]-1, k);
        }
        // Otherwise we have two cases either to include the word 
        // in the same or not to include in the same line
        else{
            int includeInThisLine = solve(ind+1, nums, remSpaces-nums[ind]-1, k);
            
            int excludeFromThisLine = (remSpaces+1)*
            (remSpaces+1) + solve(ind+1, nums, k-nums[ind]-1, k);
            
            ans = min(includeInThisLine, excludeFromThisLine);
        }
        dp[ind][remSpaces] = ans;
        return dp[ind][remSpaces];
    }

    int solveWordWrap(vector<int>nums, int k) 
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, nums, k, k);
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends