//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
public:
int revrse(int n){
    int sum=0;
    while(n>0){
        sum=sum*10+n%10;
        n=n/10;
    }
    return sum;
}
    int PalinArray(int a[], int n)
    {
    	for(int i=0;i<n;i++){
    	    if(a[i]!=revrse(a[i])){
    	        return 0;
    	    }
    	    
    	}
    	return true;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends