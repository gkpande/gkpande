//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int xor1=0;
        for(int i=0;i<nums.size();i++){
            xor1=xor1^nums[i];  //taking the xor of all element of array.
        }
        //the bits set in in xor1 ether set in any one of num not in both.
        //find right most set bit in xor1;
        xor1=xor1 & ~(xor1-1);
        //divide elemnt of nums in to two group based on set bit.
        int a=0;
        int b=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] & xor1){
                a=a^nums[i];
            }else{
                b=b^nums[i];
            }
        }
        vector<int>ans;
        if(a>b){
            ans.push_back(b);
            ans.push_back(a);
            return ans;
        }
        ans.push_back(a);
        ans.push_back(b);
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