//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
    int valid(string str){
        for(int i=0;i<str.size();i++){
            if(str[i]>='a' && str[i]<='z'){
                return 0;
            }
        }
        // cout<<str<<".";
        if(str.size()==0 || (str.size()>1 && str[0]=='0')){
            return 0;
        }
        if(stoi(str)>255){
            return 0;
        }
        return 1;
    }
        int isValid(string s) {
            
            string str="";
            int countDot=0;
            int len=s.length();
            for(int i=0;i<len;i++){
                // if(s[i]=='a'||s[i]=='b'||s[i]=='c'||s[i]=='d'){
                //     return 0;
                // }
                if(s[i]!='.'){
                    str=str+s[i];
                }
                else{
                    countDot++;
                    if(!valid(str)){
                        return 0;
                    }
                    str="";
                }
            }
            if(!valid(str)){
                return 0;
            }
            if(countDot!=3){
                return 0;
            }
            return 1;
        }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends