//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
      vector<int>ans;
      int xor1=0;
      for(int i=0;i<nums.size();i++){
          xor1 ^=nums[i];
      }
      xor1=xor1 & (~(xor1-1));
      int sum1=0,sum2=0;
      for(int i=0;i<nums.size();i++){
          if((nums[i]&xor1) > 0) {
              sum1 ^=nums[i];
          }
          else{
              sum2 ^=nums[i];
          }
      }
      if(sum1<sum2){
         ans.push_back(sum1);
         ans.push_back(sum2);
      }
      else{
          ans.push_back(sum2);
          ans.push_back(sum1);
      }
      
      
      return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends