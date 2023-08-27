//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
int solveBackTrackBFS(int s1,int s2,int t1,int t2,vector<vector<int>>&vis,int n,int step){
    queue<pair<pair<int,int>,int>>q;
    q.push({{s1,s2},step});
    vis[s1][s2]=1;
    int arr[2][8]={{2,2,1,-1,-2,-2,1,-1},{-1,1,-2,-2,-1,1,2,2}};
    while(!q.empty()){
        auto p=q.front();
        q.pop();
        s1=p.first.first;
        s2=p.first.second;
        step=p.second;
        if(s1==t1 && s2==t2){
            return step;
        }
        for(int i=0;i<8;i++){
        //if safe in all direction
            int x=s1+arr[0][i];
            int y=s2+arr[1][i];
            if(x>=0 && x<n && y>=0 && y<n && vis[x][y]==0){
                q.push({{x,y},step+1});
                vis[x][y]=1;
            }
        }
    }
    return -1;
    
    
}
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    vector<vector<int>>vis(N,vector<int>(N,0));
	    return solveBackTrackBFS(KnightPos[0]-1,KnightPos[1]-1,TargetPos[0]-1,TargetPos[1]-1,vis,N,0);
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