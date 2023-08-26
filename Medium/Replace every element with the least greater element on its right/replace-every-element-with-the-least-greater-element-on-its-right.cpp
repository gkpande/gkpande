//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

    static bool cmp(pair<int,int> a,pair<int,int> b){
        if(a.first==b.first){
            return a.second>b.second;
        }
        return a.first<b.first;
    }
class Solution{
    public:
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        //store each element wiht its index into temproray array
        vector<pair<int,int>>temp;
        for(int i=0;i<n;i++){
            temp.push_back(make_pair(arr[i],i));
        }
        //sort the temp array accroding to value.

        sort(temp.begin(),temp.end(),cmp);
        // for(int i=0;i<n;i++){
        //     cout<<"{"<<temp[i].first<<","<<temp[i].second<<"}";
        // }
        //since temp is sorted so for each index i this may be least greator element
        //to all preve element
        stack<int>st;
        vector<int>res(n,-1);
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            if(st.empty() || temp[i].second < st.top()){
                st.push(temp[i].second);
            }
            else{
                while(!st.empty() && st.top()<=temp[i].second ){
                    res[st.top()]=temp[i].second;
                    st.pop();
                }
                st.push(temp[i].second);
            }
        }
        
        for(int i=0;i<n;i++){
            if(res[i]!=-1){
                ans[i]=arr[res[i]];   
            }
            
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
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findLeastGreater(arr, n);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout <<endl;
	}
	return 0;
}

// } Driver Code Ends