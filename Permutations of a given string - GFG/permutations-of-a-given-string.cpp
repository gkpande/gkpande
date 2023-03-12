//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void solve(string s,set<string>&st,int index,int len){
	    if(index==len){
	        st.insert(s);
	        return;
	    }
	    
	    for(int i=index;i<len;i++){
	        swap(s[index],s[i]);
	        solve(s,st,index+1,len);
	        swap(s[index],s[i]);
	    }
	    
	}
		vector<string>find_permutation(string S)
		{
		    
		    set<string>st;
		    int len=S.size();
		    solve(S,st,0,len);
		    vector<string>ans(st.begin(),st.end());
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends