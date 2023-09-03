//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        stack<string>st;
        string str="";
        for(int i=0;i<S.size();i++){
            if(S[i]!='.'){
                str =str+S[i];
            }
            if(S[i]=='.'){
            
                    
                st.push(str);
                
                str="";
            }
        }
        st.push(str);
        string res="";
        while(!st.empty()){
            string temp=st.top();;
            res =res+temp;
            res=res+".";
            st.pop();
        }
        res.pop_back();
        return res;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends