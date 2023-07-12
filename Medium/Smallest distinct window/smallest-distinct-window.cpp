//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string s)
    {
        int mp[256]={0},count=0;
        string p="";
        for(int i=0;i<s.length();i++){
            if(mp[s[i]]==0){
                
                p=p+s[i];
                count++;
                mp[s[i]]++;
            }
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
        
        return ans;

        
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends