//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int a[], int num){
            if (num == 1)
        return a[0];
 
    // Initialize sum variable which store total sum of the array.
    int sum = 0;
    for (int i = 0; i < num; i++) {
        sum += a[i];
    }
 
    // Initialize every variable with first value of array.
    int curr_max = a[0], max_so_far = a[0], curr_min = a[0], min_so_far = a[0];
 
    // Concept of Kadane's Algorithm
    for (int i = 1; i < num; i++) {
        // Kadane's Algorithm to find Maximum subarray sum.
        curr_max = max(curr_max + a[i], a[i]);
        max_so_far = max(max_so_far, curr_max);
 
        // Kadane's Algorithm to find Minimum subarray sum.
        curr_min = min(curr_min + a[i], a[i]);
        min_so_far = min(min_so_far, curr_min);
    }
 
    if (min_so_far == sum)
        return max_so_far;
 
    // returning the maximum value
    return max(max_so_far, sum - min_so_far);

        // if(num==1){
        //     return arr[0];
        // }
        // int sum=0;
        // for(int i=0;i<num;i++){
        //     sum=sum+arr[i];
        // }
        // int maxSum=arr[0];
        // int maxTillHere=arr[0];
        // int minSum=arr[0];
        // int minTillHere=arr[0];
        // for(int i=1;i<num;i++){
        //     maxSum=max(maxSum+arr[i],arr[i]);
        //     maxTillHere=max(maxSum,maxTillHere);
        //     minSum=min(minSum+arr[i],arr[i]);
        //     minTillHere=min(minSum,minTillHere);
        // }
        // if(sum==minTillHere){
        //     return sum;
        // }
        // int ans=max(maxTillHere,sum-minTillHere);
        // return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends