//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
 void bs(vector<vector<int> >&arr, int m,int row, int &indexPos){
     int s=0;
     int e=m-1;
     while(s<=e){
         int mid=s+(e-s)/2;
         if(arr[row][mid]==1){
             indexPos=mid;
             e=mid-1;
         }
         else{
             s=mid+1;
         }
     }
 }
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int row;
	    int indexPos=-1;
	    int prevIndexPos =INT_MAX;
	    for(int i=0;i<n;i++)
	    {
	        bs(arr,m,i,indexPos);
	        if(indexPos==0){
	            return i;
	        }
	        if(indexPos>0){
	            row=i;
	            break;
	        }
	        
	    }
	    if(indexPos==-1){
	        return -1;
	    }
	   for(int i=1;i<n;i++){
	        for(int j=indexPos;j>=0;j--){
	         if(arr[i][j]==1 && j-1>=0 && arr[i][j-1]==1){
	            indexPos=j-1;
	           if(indexPos<prevIndexPos){
	            row=i;
	            prevIndexPos=indexPos;
	        }
	            }   
	        }
	        
	          
	   }
	    return row;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends