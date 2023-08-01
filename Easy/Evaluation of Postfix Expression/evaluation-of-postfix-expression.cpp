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
        stack<int>operand;
        for(int i=0;i<S.length();i++){
            if(S[i]!='*' && S[i]!='+' && S[i]!='-' && S[i]!='/'){
                operand.push(S[i]-'0');
            }
            else{
                int b=operand.top();
                
                operand.pop();
                int a=operand.top();
                operand.pop();
                int c;
                if(S[i]=='+'){
                    c=a+b;
                }
                if(S[i]=='-'){
                    c=a-b;
                }
                if(S[i]=='*'){
                    c=a*b;
                }
                if(S[i]=='/'){
                    c=a/b;
                }
                operand.push(c);
            }
        }
        return operand.top();
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