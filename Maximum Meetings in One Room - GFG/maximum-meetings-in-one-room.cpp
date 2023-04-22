//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
static bool comp(pair<int,int>a,pair<int,int>b){
        return a.second<b.second;
    }
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        //create a vector of pair containing start index and end time
        vector<pair<int ,int>>meeting;
        for(int i=0;i< N; i++){
            meeting.push_back(make_pair(i,F[i]));
        }
        //sort the meeting according to end time
        sort(meeting.begin(),meeting.end(),comp);
        vector<int>ans;
        ans.push_back(meeting[0].first+1);
        int endTime=meeting[0].second;
        for(int i=1;i<N;i++){
            if(S[meeting[i].first]>endTime){
                ans.push_back(meeting[i].first+1);
                endTime=meeting[i].second;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends