//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    bool isValid(int nx,int ny, vector<vector<bool>>&visited,int n)
    {
       
        if((nx>=0 && nx<n) &&(ny>=0 && ny<n) && visited[nx][ny]==false){
            return true;
        }
        else{
            return false;
        }
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int n=N;
	   int x=KnightPos[0]-1;
	   int y=KnightPos[1]-1;
	   int tx=TargetPos[0]-1;
	   int ty=TargetPos[1]-1;
	   if(x==tx && y==ty){
	       return 0;
	   }
	   queue<pair<int,int>>q;
	   q.push({x,y});
	   vector<vector<bool>>visited(n,vector<bool>(n,false));
	   visited[x][y]=true;
	   int ans=0;
	   int xarr[8]={1,1,-1,-1,2,2,-2,-2};
	   int yarr[8]={2,-2,2,-2,-1,1,-1,1};
	   while(!q.empty()){
	       int size=q.size();
	       ans++;
	       while(size>0){
	           pair<int ,int>p=q.front();
	           q.pop();
	           int xx=p.first;
	           int yy=p.second;
	          
	           for(int i=0;i<8;i++){
	               int nx=xx+xarr[i];
	               int ny=yy+yarr[i];
	               if(nx==tx && ny==ty){
	                   return ans;
	               }
	               if(isValid(nx,ny,visited,N)){
	                   visited[nx][ny]=true;
	                   q.push({nx,ny});
	               }
	           }
	        size--;
	       }
	      
	   }
	   return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends