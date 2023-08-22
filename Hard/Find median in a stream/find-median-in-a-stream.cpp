//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    priority_queue<int>maxHeap;  //to store left half of median
    priority_queue<int,vector<int>,greater<int>>minHeap; //to store right half of median 
    void insertHeap(int &x)
    {
        if(maxHeap.size()==0){
            maxHeap.push(x);
            return;
        }
        if(maxHeap.size()>minHeap.size()){
            if(maxHeap.top()>=x){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(x);
            }
            else{
                minHeap.push(x);
            }
        }
        else{
            if(maxHeap.top()>x){
                maxHeap.push(x);
            }
            else{
                minHeap.push(x);
                maxHeap.push(minHeap.top());
                minHeap.pop();
                
                
            }
        }
        
        
}
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(minHeap.size()==maxHeap.size()){
            return (minHeap.top()*1.0+maxHeap.top()*1.0)/2.0;
        }
        return maxHeap.top()*1.0;
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends