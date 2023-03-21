//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        int ans=0;
        int count=0;
        int i=0;
        int n=str.size();
        
        while(i<n){
            if(str[i]=='0'){
                while(i<n && str[i]=='0'){
                    count++;
                    i++;
                }
                while(i<n && str[i]=='1' && count!=0){
                    count--;
                    i++;
                }
                if(count==0){
                    ans++;
                }
            }
            else{
                while(i<n && str[i]=='1'){
                    count++;
                    i++;
                }
                while(i<n && str[i]=='0' && count!=0){
                    count--;
                    i++;
                }
                if(count==0){
                    ans++;
                }
            }
        }
        if(count==0){
            return ans;
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends