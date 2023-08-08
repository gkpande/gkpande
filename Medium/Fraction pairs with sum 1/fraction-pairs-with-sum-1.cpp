//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    int gcd(int a,int b){
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;

    }
    int countFractions(int n, int numerator[], int denominator[])
    {
        unordered_map<string,int>mp;
        int count=0;
        for(int i=0;i<n;i++){
            int g=gcd(numerator[i],denominator[i]);
            int a=numerator[i]/g;
            int b=denominator[i]/g;
             string str1=to_string(b-a); 
             string str2=to_string(b);
             string str=str1+"/"+str2;
            if(mp.find(str)!=mp.end()){
                count+=mp[str];
            }
            mp[to_string(a) + "/" + to_string(b)]++;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends