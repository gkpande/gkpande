//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};


// } Driver Code Ends
/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

class Solution{
public:
    /*You are required to complete this method*/
    static bool cmp(val a, val b){
        return a.second<b.second;
    }
    int solve(struct val p[],int n){
        sort(p,p+n,cmp);
        int count=1;
        int end=p[0].second;
        for(int i=1;i<n;i++){
            int start=p[i].first;
            if(start>end){
                end=p[i].second;
                count++;
            }
        }
        return count;
    }
    int solveRec(struct val p[],int n,int prev,int curr){
        
        if(curr==n){
            return 0;
        }
        int take=0;
        if(prev=-1||p[prev].second<p[curr].first){
            take=1+solveRec(p,n,curr,curr+1);
        }
        int notTake=0+solveRec(p,n,prev,curr+1);
        return max(take,notTake);
    }
    int maxChainLen(struct val p[],int n){
        //sove using greedy. sort p according to finish time 
        return solve(p,n);
        // return solveRec(p,n,-1,0);
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
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		Solution ob;
		cout<<ob.maxChainLen(p,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends