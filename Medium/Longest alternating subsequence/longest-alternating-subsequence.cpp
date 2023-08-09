//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	int solve1(vector<int>&nums){
	    int n=nums.size();
	    if(n==1){
	        return 1;
	    }
	    int arr[n][2];
	    for(int i=0;i<n;i++){
	        arr[i][0]=arr[i][1]=1;
	    }
	    int res;
	    for(int i=1;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(nums[j]<nums[i]){
	                if(arr[i][0]<arr[j][1]+1){
	                    arr[i][0]=arr[j][1]+1;
	                }
	            }
	            if(nums[j]>nums[i]){
	                if(arr[i][1]<arr[j][0]+1){
	                    arr[i][1]=arr[j][0]+1;
	                }
	            }
	        }
	        if(arr[i][0]<arr[i][1]){
	            res=arr[i][1];
	        }
	        else{
	            res=arr[i][0];
	        }
	        
	    }
	    return res;
	}
	int solve2(vector<int>&nums){
	    int inc=1,dec=1;
	    for(int i=1;i<nums.size();i++){
	        if(nums[i]>nums[i-1]){
	            inc=dec+1;
	        }else if(nums[i]<nums[i-1]){
	            dec=inc+1;
	        }
	    }
	    return max(inc,dec);
	}
		int AlternatingaMaxLength(vector<int>&nums){
		  //  return solve1(nums);//time O(n^2) space O(n)
		    return solve2(nums);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.AlternatingaMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends