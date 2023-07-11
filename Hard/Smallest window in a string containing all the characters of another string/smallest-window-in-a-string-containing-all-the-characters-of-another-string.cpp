//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        int mp[256]={0};//store frequency of each char in pattern
        int count=0;//to store num of distinct char in pattern.
        //stroring frequency and counting distinct character.
        for(int i=0;i<p.length();i++){
            if(mp[p[i]]==0){
                count++;
            }
            mp[p[i]]++;;
        }
        int start=0,i=0,j=0,ans=INT_MAX;
        while(j<s.length()){
            mp[s[j]]--;
            if(mp[s[j]]==0){
                count--;
            }
            if(count==0){    //count=0 means we have found a window which conatin pattern
                //need to shrenk
                while(count==0){
                    if(ans> j-i+1){
                        ans=min(ans,j-i+1);
                        start=i;
                    }
                    mp[s[i]]++;
                    if(mp[s[i]]>0){
                        count++;
                    }
                    i++;
                }
            }
            j++;
        }
        if(ans==INT_MAX){
            return "-1";
        }
        return s.substr(start,ans);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends