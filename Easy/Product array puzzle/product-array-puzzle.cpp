//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       vector<long long int>ans(n,0);
       long long int prod=1;
       int temp=0;
       int ind;
       for(int i=0;i<n;i++){
           if(nums[i]!=0){
               prod=prod*nums[i];
           }else{
               temp++;
               ind=i;
           }
       }
       if(temp>=2){
           return ans;
       }
       if(temp==1){
           ans[ind]=prod;
           return ans;
       }
       for(int i=0;i<n;i++){
           ans[i]=prod/nums[i];
       }
       return ans;
               
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends