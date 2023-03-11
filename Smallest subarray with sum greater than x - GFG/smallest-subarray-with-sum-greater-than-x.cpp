//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        int s=0;
        int e=0;
        int len=n+1;
        int currSum=0;
        while(e<n){
            while(currSum<=x && e<n){
                currSum+=arr[e];
                e++;
            }
           
            while(currSum>x && s<n){
                if(e-s<len){
                    len=e-s;
                }
                currSum -= arr[s];
                s++;
            
            }
        }
        return len;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends