//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        int num=0;
        unordered_map<char,int>mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        int len=str.length();
        int i=0;
        while(i<len-1){
            if(mp[str[i]]<mp[str[i+1]]){
                num+=(mp[str[i+1]]-mp[str[i]]);
                i+=2;
            }else{
                num +=mp[str[i]];
                i++;
            }
        }
        num+=mp[str[i]];
        return num;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends