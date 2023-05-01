//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
       int open=0;
       int close=0;
       int flen=0;
       //from left to right
       for(int i=0;i<s.length();i++){
           if(s[i]=='('){
               open++;
           }
           else{
               close++;
           }
           if(open==close){
               flen=max(flen,2*open);
           }
           else if(close>open){
               close=0;
               open=0;
           }
       }
       //from right to left
       open=0;close=0;
       for(int i=s.length()-1;i>=0;i--){
           if(s[i]=='('){
               open++;
           }
           else{
               close++;
           }
           if(open==close){
               flen=max(flen,2*open);
           }
           else if(open>close){
               close=0;
               open=0;
           }
       }
       return flen;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends