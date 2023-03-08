//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string solve(int arr[], int n) {
      sort(arr, arr + n);
        string a="";
        string b="";
        for (int i = 0; i < n; i ++) {
            if(i%2==0){
             a += (arr[i] + '0');
        }
        else
        {
             b += (arr[i] + '0');
        }
        }
        
        int j = a.length() - 1;
        int k = b.length() - 1;
        int carry = 0;
        string ans = "";
        while (j >= 0 && k >= 0) {
            int sum = 0;
            sum += (a[j] - '0') + (b[k] - '0') + carry;
            ans += to_string(sum % 10);
            carry = sum / 10;
            j--;
            k--;
        }
        while(j>=0){
           
              int val=(a[j]-'0')+carry;
              ans +=to_string(val%10);
                carry=val/10;
                 
            
            j--;
        }
        while(k>=0){
            
              int val=(b[k]-'0')+carry;
              ans += to_string(val%10);
                carry=val/10;
                k--; 
            
        }
        if(carry==1){
            ans += to_string(carry);;
        }
        
        while (!ans.empty() && ans.back() == '0')
            {
                ans.pop_back();
            
            }
        reverse(ans.begin(),ans.end());
        return ans;
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends