//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        stack<char>st;
        st.push(S[0]);
        int len=S.length();
        for(int i=1;i<len;i++){
            if(S[i]==st.top()){
                S.erase(i,1);
                len=S.length();
                i--;
            }else{
                st.push(S[i]);
            }
        }
        return S;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 




// } Driver Code Ends