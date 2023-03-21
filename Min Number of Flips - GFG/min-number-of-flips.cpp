//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minFlips (string S)
{
    char ch1;
    char ch2;
    int ans1;
    int ans2;
    
    if(S[0]=='0'){
        ch1='0';
        ch2='1';
        ans1=0;
        ans2=1;
    }
    else{
        ch1='0';
        ans1=1;
        ch2='1';
        ans2=0;
    }
    
    for(int i=1;i<S.size();i++){
        if(S[i]==ch1){
            if(ch1=='0'){
                ch1='1';
                ans1++;
                
            }
            else if(ch1=='1'){
                ch1='0';
                ans1++;
            }
        }
        else{
            ch1=S[i];
        }
        if(S[i]==ch2){
            if(ch2=='0'){
                ch2='1';
                ans2++;
                
            }
            else if(ch2=='1'){
                ch2='0';
                ans2++;
            }
        }
        else{
            ch2=S[i];
        }
        
    }
    // cout<<ans1<<ans2;
    return min(ans1,ans2);
}