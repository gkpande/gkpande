//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
  public:
  void inorder(vector<int>&A,int n,int i,vector<int>&inTrav){
      if(i>=n){
          return;
      }
      inorder(A,n,2*i+1,inTrav);
      inTrav.push_back(i);
      inorder(A,n,2*i+2,inTrav);
      
  }
    int minSwaps(vector<int>&A, int n){
        //write inorder traversal of array
        vector<int>inTrav;
        inorder(A,n,0,inTrav);
        //create a map array to store pair of {arr[i],i}
        pair<int,int>mapArr[n];
        for(int i=0;i<n;i++){
            mapArr[i]={inTrav[i],i};
        }
        //sort the mapArr
        sort(mapArr,mapArr+n);
        //find the total cycle in mapArr
        int count=0;  //num of swap require
        vector<int>visited(n,0);//to detect the cycle you need visited array
        for(int i=0;i<n;i++){
            if(visited[i] || i==mapArr[i].second){
                continue;
            }
            else{
                int j=i;
                int cycleLen=0; //cycle length
                while(!visited[j]){
                    visited[j]=1;
                    cycleLen++;
                    j=mapArr[j].second;
                }
                if(cycleLen>0){
                    count +=cycleLen-1;
                }
            }
        }
       return count; 
    }
    
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>A(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> A[i];
	    }
	    Solution ob;
	    int ans = ob.minSwaps(A, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends