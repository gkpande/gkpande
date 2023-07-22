//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        int arr[26]={0};
        priority_queue<pair<int,char>>pq;
        for(int i=0;i<s.length();i++){
            arr[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(arr[i]>0){
                pq.push({arr[i],'a'+i});
            }
        }
        int sum=0;
        while(!pq.empty() && k>0){
            auto element=pq.top();
            int first=element.first;
            pq.pop();
            char second=element.second;
            arr[second-'a']--;
            k--;
            pq.push({arr[second-'a'],second});
        }
        for(int i=0;i<26;i++){
            if(arr[i]>0){
                sum +=(arr[i]*arr[i]);
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends