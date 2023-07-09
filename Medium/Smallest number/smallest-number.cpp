//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
        if(9*D<S){
            return "-1";
        }
        string ans="";
        for(int i=D-1;i>=0;i--){
            if(S>9){
                ans='9'+ans;
                S-=9;
            }
            else{
                //may be last digit
                if(i==0){
                    ans=to_string(S)+ans;
                }
                else{
                    ans=to_string(S-1)+ans;
                    i--;
                    while(i>0){
                        ans='0'+ans;
                        i--;
                    }
                    ans='1'+ans;
                    break;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends