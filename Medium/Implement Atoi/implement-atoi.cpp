//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int convertAtoi(string str,int i){
        int num=0;
        while(i<str.size()){
            if(str[i]>='0' &&  str[i]<='9'){
                num=num*10+(str[i]-'0');
                i++;
            }
            else{
                return -1;
            }
            
            
        }
        return num;
    }
    int atoi(string str) {
        int ans;
        if(str[1]=='-'){
            return -1;
        }
        if(str[0]=='-'){
            ans=convertAtoi(str,1);
            if(ans==-1){
                return -1;
            }
            return -1*ans;
        }
        else{
            ans=convertAtoi(str,0);
            if(ans==-1){
                return -1;
            }
            return ans;
        }
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
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends