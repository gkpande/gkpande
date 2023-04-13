//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        int count=1;
        if(N==1){
            return 1;
        }
        else if(N%2==1 || N==0){
            return -1;
        }
        else{
            while(N>1){
                N=N/2;
                count++;
                if(N>2 && N%2==1){
                    return -1;
                }
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
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends