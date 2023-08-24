//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
        string ans = "";
    string u = "";
    string v = "";
    
    if (s1[0] == '-') {
        u = s1.substr(1);
    } else {
        u = s1;
    }
    if (s2[0] == '-') {
        v = s2.substr(1);
    } else {
        v = s2;
    }
    
    int m = u.size();
    int n = v.size();
    
    vector<int> products(m + n, 0);
    
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            products[i + j + 1] += (u[i] - '0') * (v[j] - '0');
        }
    }
    
    int carry = 0;
    for (int i = m + n - 1; i >= 0; i--) {
        int sum = products[i] + carry;
        products[i] = sum % 10;
        carry = sum / 10;
    }
    
    for (int num : products) {
        ans += char(num + '0'); 
    }
    
    while (!ans.empty() && ans[0] == '0') {
        ans.erase(ans.begin());
    }
    
    if ((s1[0]=='-'&&s2[0]!='-')||(s2[0]=='-'&&s1[0]!='-')) {
        ans = "-" + ans;
    }
    
    return ans.empty() ? "0" : ans;

    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends