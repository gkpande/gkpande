//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack<int>st;
        int op1,op2;
        for(int i=0;i<S.length();i++){
            if((S[i]-'0')<=9 && (S[i]-'0')>=0 ){
                st.push(S[i]-'0');
            }
            else {
                if(S[i]=='*'){
                op2=st.top();
                st.pop();
                op1=st.top();
                st.pop();
                st.push(op1 * op2);
                }
                else if(S[i]=='/'){
                    op2=st.top();
                    st.pop();
                    op1=st.top();
                    st.pop();
                    st.push(op1 / op2);
                }
                else if(S[i]=='+'){
                    op2=st.top();
                    st.pop();
                    op1=st.top();
                    st.pop();
                    st.push(op1 + op2);
                }
                else if(S[i]=='-'){
                    op2=st.top();
                    st.pop();
                    op1=st.top();
                    st.pop();
                    st.push(op1 - op2);
                }
                
            }
        }
        return st.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends