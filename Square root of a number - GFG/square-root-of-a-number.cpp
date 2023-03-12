//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
  long long int solve(long long int start,long long int end,long long int x){
      long long int mid;
      while(start<=end){
          mid=start+(end-start)/2;
          if(mid*mid==x){
              return mid;
          }
          else if(mid*mid<x){
              start=mid+1;
          }
          else{
              end=mid-1;
          }
      }
      if(mid*mid<=x){
        return mid;
      }
      else{
          return mid-1;
      }
  }
    long long int floorSqrt(long long int x) 
    {
        long long int start=1;
        long long int end=x;
        return solve(start,end,x);
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends