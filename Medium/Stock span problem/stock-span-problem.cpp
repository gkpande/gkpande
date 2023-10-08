//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.ta
    void findPrevGreator(int price[],int n,vector<int>&pg){
        stack<int>st;
        st.push(-1);
        for(int i=0;i<n;i++){
            while(st.top()!=-1 && price[st.top()]<=price[i]){
                st.pop();
            }
            if(st.top()!=-1 && price[st.top()]>price[i]){
                pg.push_back(st.top());
                st.push(i);
            }else{
                pg.push_back(-1);
                st.push(i);
            }
        }
    }
    vector <int> calculateSpan(int price[], int n)
    {
       vector<int>ans;
       vector<int>prevGreator;
       findPrevGreator(price,n,prevGreator);
       for(int i=0;i<n;i++){
           
               ans.push_back(i-prevGreator[i]);
           
           
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
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends