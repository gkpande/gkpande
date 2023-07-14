//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    int len=s.length();
    int countRev=0;
    stack<char>st;
    for(int i=0;i<len;i++){
        if(st.empty() && s[i]=='}'){
            countRev++;
            st.push('{');
        }
        else if(s[i]=='{'){
            st.push('{');
        }
        else if(st.top()=='{' && s[i]=='}'){
            st.pop();
        }
    }
    if(st.size()%2==1){
        return -1;
    }
    return st.size()/2+countRev;
}