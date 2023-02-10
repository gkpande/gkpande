//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class node{
    public:
    int data;
    int row;
    int col;
    node(int d,int i,int j){
        data=d;
        row=i;
        col=j;
    }
};
class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data>b->data;
    }
};
class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
          priority_queue<node* ,vector<node*>,compare>m;
          int maxi=0;
          for(int i=0;i<k;i++){
              node* temp=new node(KSortedArray[i][0],i,0);
              m.push(temp);
              maxi=max(maxi,KSortedArray[i][0]);
          }
          int start=m.top()->data;
          int end=maxi;
          int mini=m.top()->data;
          while(!m.empty()){
              node* temp=m.top();
              int r=temp->row;
              int c=temp->col;
              mini=temp->data;
              m.pop();
              if(maxi-mini < end - start){
                  start=mini;
                  end=maxi;
              }
              if(c+1< n){
                  maxi=max(maxi,KSortedArray[r][c+1]);
                  m.push(new node(KSortedArray[r][c+1],r,c+1));
              }
              else{
                  break;
              }
              
          }
          //cout<<"start="<<start<<"end="<<end;
          pair<int,int>p;
          p.first=start;
          p.second=end;
          return p;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends