//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
int upperBound(vector<int>arr,int c,int x){
    int low=0,high=c-1;
    int ans=c;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>x){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int countElement(vector<vector<int>>&matrix,int r,int c,int mid){
    int ans=0;
    for(int i=0;i<r;i++){
        ans +=upperBound(matrix[i],c,mid);
    }
    // cout<<ans<<"-";
    return ans;
}
    int median(vector<vector<int>> &matrix, int R, int C){
        //find min and max element
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<R;i++){
            mini=min(mini,matrix[i][0]);
            maxi=max(maxi,matrix[i][C-1]);
        }
        int low=mini,high=maxi;
        // cout<<low<<"-"<<high<<"-";
        int req=(R*C)/2;
        while(low<=high){
            int mid=low+(high-low)/2;
            //count number of element less than mid
            int countEle=countElement(matrix,R,C,mid);
            
            //count should be less than req means 50%
            if(countEle<=req){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        
        return low;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends