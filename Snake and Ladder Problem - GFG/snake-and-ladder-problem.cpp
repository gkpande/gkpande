//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        vector<int>move(31,-1);
        for(int i=0;i<2*N;i=i+2){
            move[arr[i]]=arr[i+1];
        }
        // for(int i=0;i<31;i++){
        //     cout<< move[i]<<" ";
        // }
        vector<int>visited(31,0);
        queue<pair<int,pair<int,int>>>q;//source destination steps;
        int src=1,dest=1,step=1;
        visited[1]=1;
        q.push({1,{1,1}});
        
        while(!q.empty()){
                pair<int,pair<int,int>>p=q.front();
                src=p.first;
                dest=p.second.first;
                step=p.second.second;
                // cout<<src<<dest<<step<<"--";
                q.pop();
                int a,j;
                for( j=dest+1;j<=dest+6 && j<31;j++){
                    
                    if(visited[j]==0 && j!=30){
                        
                        if(move[j]==-1){
                            
                            a=j;
                        }
                        else {
                            // a=move[j];
                            q.push({j,{move[j],step+1}});
                            visited[j]=1;
                        }
                    }
                    else if(j==30){
                        // step=step+1;
                        return step;
                    }
                }
                visited[a]=1;
                q.push({j,{a,step+1}});    
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends