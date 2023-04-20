//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int n=nums.size();
	    pair<int,int>mapArr[n];
	    //add each element of nums along with there index in mapArr
	    for(int i=0;i<n;i++){
	        mapArr[i]={nums[i],i};
	    }
	    //sort the mapArr 
	    sort(mapArr,mapArr+n);
	    //create visited array;
	    vector<int>visited(n,0);
	    int count=0;
	    for(int i=0;i<n;i++){
	        int cycleSize=0;
	        if(visited[i]==1||i==mapArr[i].second){
	            continue;
	        }
	        int j=i;
	        while(!visited[j]){
	            visited[j]=1;
	            j=mapArr[j].second;
	            cycleSize++;
	        }
	        if(cycleSize>0){
	            count=count+cycleSize-1;
	        }
	    }
	    return count;
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
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends