//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string S){
        int start,end;
        int len=0;
        int low,hi;
        int n=S.length();
        for(int i=0;i<S.length();i++){
            //check for odd
            low=i-1;
            hi=i+1;
            while(low>=0 && hi<n && S[low]==S[hi]){
                if(hi-low+1>len){
                    start=low;
                    end=hi;
                    len=hi-low+1;
                }
                low--;hi++;
            }
            //check for even
            low=i-1;hi=i;
            while(low>=0 && hi<n && S[low]==S[hi]){
                if(hi-low+1>len){
                    start=low;
                    end=hi;
                    len=hi-low+1;
                }
                low--;hi++;
            }
        }
        if(len==0){
            return S.substr(0,1);
        }
        return S.substr(start,end-start+1);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends