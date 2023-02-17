//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int findFirstIndex(int arr[],int n,int x,int left,int right){
    if(left>right){
        return -1;
    }
    int mid=left+(right-left)/2;
    if(arr[mid]==x){
        if(mid==left){
            return mid;
        }
        if(arr[mid-1]<x){
            return mid;
        }
        else{
            return findFirstIndex(arr,n,x,left,mid-1);
        }
    }
    else if(arr[mid]>x){
        return findFirstIndex(arr,n,x,left,mid-1);
    }
    else{
        return findFirstIndex(arr,n,x,mid+1,right);
    }
}
int findSecondIndex(int arr[],int n,int x,int left,int right){
    if(left>right){
        return -1;
    }
    int mid=left+(right-left)/2;
    if(arr[mid]==x){
        if(mid==right){
            return mid;
        }
        if(arr[mid+1]>x){
            return mid;
        }
        else{
            return findSecondIndex(arr,n,x,mid+1,right);
        }
    }
    else if(arr[mid]>x){
        return findSecondIndex(arr,n,x,left,mid-1);
    }
    else{
        return findSecondIndex(arr,n,x,mid+1,right);
    }
}
vector<int> find(int arr[], int n , int x )
{
    vector<int>ans;
    ans.push_back(findFirstIndex(arr,n,x,0,n-1));
    ans.push_back(findSecondIndex(arr,n,x,0,n-1));
    return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends