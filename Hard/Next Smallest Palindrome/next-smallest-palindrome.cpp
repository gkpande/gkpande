//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
bool isAll9s(int num[],int n){
    for(int i=0;i<n;i++){
        if(num[i]!=9){
            return false;
        }
    }
    return true;
}
	vector<int> generateNextPalindrome(int num[], int n) {
	    vector<int>ans;
	    //if palindrom and all are 9's.
	    if(isAll9s(num,n)){
	        ans.push_back(1);
	        for(int i=0;i<n-1;i++){
	            ans.push_back(0);
	        }
	        ans.push_back(1);
	        return ans;
	    }
	    int mid=n/2;
	    //case2: num may be palindrom or not
	    int i=mid-1;
	    int j=(n%2)?mid+1:mid;
	    while(i>=0 && num[i]==num[j]){//8 3 4 2 2  4 6 9
	        i--;
	        j++;
	    }
	    bool leftIsSmall=false;
	    if(i<0 || num[i]<num[j]){ //1 2 2 1,8 3 4 2 2  4 6 9
	        leftIsSmall=true;
	    }
	    // left is not small than nothing to do
	    while(i>=0){
	        num[j]=num[i];
	        i--;
	        j++;
	    }//8 3 4 2 2 4 3 8 
	    if(leftIsSmall==true){
	        int carry=1;
	        i=mid-1;
	        if(n%2==1){
	            num[mid]=num[mid]+carry;
	            carry=num[mid]/10;
	            num[mid]=num[mid]%10;
	            j=mid+1;
	        }else{
	            j=mid;
	        }
	        while(i>=0){
	            num[i]=num[i]+carry;
	            carry=num[i]/10;
	            num[i]=num[i]%10;
	            num[j]=num[i];
	            i--;
	            j++;
	        }
	    }
	    for(int i=0;i<n;i++){
	        ans.push_back(num[i]);
	    }
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
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends