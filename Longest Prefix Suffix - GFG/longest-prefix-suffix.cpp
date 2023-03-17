//{ Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    int n=s.length();
	    int i=n-2;
	    int j=n-1;
	    int count=0;
	    
	    while(i>=0){
	        if(s[i]==s[j]){
	            count++;
	            i--;
	            j--;
	        }
	        else{
	            count=0;
	            if(j!=n-1){
	                j=n-1;
	            }
	            else{
	                i--;
	            }
	         }
	    }
	   
	    return count;
	}
};

//{ Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}

// } Driver Code Ends