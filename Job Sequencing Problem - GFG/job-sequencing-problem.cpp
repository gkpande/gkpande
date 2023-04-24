//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool cmp(Job a,Job b){
        return a.profit > b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
       //sort the job in descending order according to profit.
       sort(arr,arr+n,cmp);
       //find the max deadline
       int maxDl=INT_MIN;
       for(int i=0;i<n;i++){
           maxDl=max(maxDl,arr[i].dead);
       }
       //create schedule array of max dealine
       vector<int>schedule(maxDl+1,-1);
       int maxProfit=0;
       int count=0;
       for(int i=0;i<n;i++){
           int currId=arr[i].id;
           int currDead=arr[i].dead;
           int currProfit=arr[i].profit;
           for(int j=currDead;j>0;j--){
               if(schedule[j]==-1){
                   count++;
                   maxProfit +=currProfit;
                   schedule[j]=currId;
                   break;
               }
           }
       }
       vector<int>ans;
       ans.push_back(count);
       ans.push_back(maxProfit);
       return ans;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends