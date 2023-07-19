//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
        
    //     stack<char>st;
    // for(int i=0; i<s.length();i++){
    //     if(s[i]=='('||s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
    //         st.push(s[i]);
    //     }
    //     else{
    //         if(s[i]==')'){
    //             bool rb=true;
    //             while(st.top()!='('){
    //                 if(st.top()=='+'||st.top()=='-'||st.top()=='*'||st.top()=='/'){
    //                     rb=false;
    //                 }
    //                 st.pop();
    //             }
    //             st.pop();
    //             if(rb==true){
    //                 return true;
    //             }
    //         }
    //     }
    // }
    // return false;
        //a bracket is redundant if no operator between bracket.
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='+' || s[i]=='-' || s[i]=='/'||s[i]=='*'){
                st.push(s[i]);
            }
            else{
                if(s[i]==')'){
                    bool redundentBra=true;
                    while(st.top()!='('){
                        if(st.top()=='+'||st.top()=='-'||st.top()=='*'||st.top()=='/'){
                            redundentBra=false;
                            
                        }
                        st.pop();
                    }
                    st.pop();  
                    if(redundentBra==true){
                        return 1;
                    }
        
                }
                
            }
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends