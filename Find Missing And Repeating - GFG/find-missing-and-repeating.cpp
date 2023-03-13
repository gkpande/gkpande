//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int *ans=new int[2];
        int xor1=0;
        for(int i=0;i<n;i++){
            xor1=xor1^arr[i];
        }
        for(int i=1;i<=n;i++){
            xor1=xor1^i;
        }
        int setbit=xor1 & ~(xor1-1);
        int x=0,y=0;
        for(int i=0;i<n;i++ ){
            if((arr[i]&setbit)>0){
                x=x^arr[i];
            }
            else{
                y=y^arr[i];
            }
        }
        for(int i=1; i<=n;i++){
            if(i & setbit){
                x=x^i;
            }
            else{
                y=y^i;
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]==x){
                ans[0]=x;
                ans[1]=y;
                return ans;
            }
        }
        ans[0]=y;
        ans[1]=x;
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends