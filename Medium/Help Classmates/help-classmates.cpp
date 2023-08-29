//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        vector<int>nextSmaller(n);
        stack<int>st;
        st.push(-1);
        for(int i=n-1;i>=0;i--){
            if(st.top()<arr[i]){
                nextSmaller[i]=st.top();
                st.push(arr[i]);
            }else{
                while(st.top()>=arr[i]){
                    st.pop();
                }
                nextSmaller[i]=st.top();
                st.push(arr[i]);
            }
        }
        return nextSmaller;
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
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}


// } Driver Code Ends