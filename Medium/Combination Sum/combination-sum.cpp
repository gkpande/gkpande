//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void solveRec(vector<int> &a,vector<vector<int>>&ans,vector<int>&tans,int b,int i){
        if(b==0){
            ans.push_back(tans);
            return ;
        }
        if(i>=a.size()){
            return;
        }
        if(a[i]<=b){
            tans.push_back(a[i]);
            solveRec(a,ans,tans,b-a[i],i);
            tans.pop_back();
        }
        solveRec(a,ans,tans,b,i+1);
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
            // sort the  array because we have to return the result in ascending order
            sort(A.begin(),A.end());
            //remove duplicates form array
            A.erase(unique(A.begin(),A.end()),A.end());
            vector<vector<int>>ans;
            vector<int>tans;
            solveRec(A,ans,tans,B,0);
            return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends