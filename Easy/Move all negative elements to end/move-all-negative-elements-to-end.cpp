//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        int a[n];
        //count num of neegative element
        int countPos=0;
        for(int i=0;i<n;i++){
            if(arr[i]>0){
               countPos++; 
            }
        }
        int r=countPos;
        int l=0;
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                a[l]=arr[i];
                l++;
            }else{
                a[r]=arr[i];
                r++;
            }
        }
        for(int i=0;i<n;i++){
            arr[i]=a[i];
        }
    }
};

//{ Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}

// } Driver Code Ends