//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int solveSoLcs(string str1, string str2,int n){
	   vector<int>curr(n+1,0);
	   vector<int>prev(n+1,0);
	    for(int i=n-1;i>=0;i--){
	        for(int j=n-1;j>=0;j--){
	            if(str1[i]==str2[j] && i!=j ){
	                curr[j]=1+prev[j+1];
	            }
	            else{
	               curr[j]=max(curr[j+1],prev[j]);
	            }
	        }
	        prev=curr;
	    }
	    
	    return prev[0];
	}

		int LongestRepeatingSubsequence(string str){
		    int n=str.length();
		    string str1=str;
		    string str2=str;
		    return solveSoLcs(str1,str2,n);

		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends