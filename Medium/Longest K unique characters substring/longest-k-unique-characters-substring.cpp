//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int longestKSubstr(string s, int k) {
        unordered_map<char, int> mp;
        int start = 0;
        int end = 0;
        int len = INT_MIN;
        
        while (end < s.length()) {
            mp[s[end]]++;  // Add the current character to the map
            
            while (mp.size() > k) {  // Shrink the window if the number of distinct characters > k
                mp[s[start]]--;
                if (mp[s[start]] == 0) {
                    mp.erase(s[start]);
                }
                start++;
            }
            
            len = max(len, end - start + 1);  // Update the maximum length
            
            end++;
        }

        if (mp.size() < k) {
            return -1;
        }
        
        return len;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends