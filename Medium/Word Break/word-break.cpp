//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int compare(string str,unordered_map<string,int>mp){
        if(mp.find(str)!=mp.end()){
            return 1;
        }
        return 0;
    }
    int solveRec(string str,vector<string> &B,unordered_map<string,int>mp){
        if(str.size()==0){
            return 1;
        }
        for(int i=1;i<=str.size();i++){
            if(compare(str.substr(0,i),mp) && solveRec(str.substr(i,str.size()-i),B,mp)){
                return 1;
            }
        }
        return 0;
    }
    int wordBreak(string A, vector<string> &B) {
        unordered_map<string,int>mp;
        for(int i=0;i<B.size();i++){
            mp[B[i]]=1;
        }
        return solveRec(A,B,mp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends