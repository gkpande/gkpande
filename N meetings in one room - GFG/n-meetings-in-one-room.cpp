//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool comp(pair<int,int>a,pair<int,int>b){
        return a.second<b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        //create a vector of pair containing start and end time
        vector<pair<int ,int>>meeting;
        for(int i=0;i< n; i++){
            meeting.push_back(make_pair(start[i],end[i]));
        }
        //sort the meeting according to end time
        sort(meeting.begin(),meeting.end(),comp);
        int count=1;
        int endTime=meeting[0].second;
        for(int i=1;i<n;i++){
            if(meeting[i].first>endTime){
                count++;
                endTime=meeting[i].second;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends