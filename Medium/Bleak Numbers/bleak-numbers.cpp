//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
int countSetBit(int x){
    unsigned int count = 0;
    while (x) {
        x &= (x - 1);
        count++;
    }
    return count;
}
int findNumBits(int n){
    int count=0;
    while(n>0){
      count++;
      n=n>>1;
    }
    return count;
}
int checkBleak(int n){
    
    for (int i=n-findNumBits(n);i<=n;i++) {
    
        if(i + countSetBit(i) ==n){
            return 0;
        }

    }

    return 1;
}
	int is_bleak(int n)
	{
	   
	    return checkBleak(n);
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends