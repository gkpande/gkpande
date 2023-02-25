//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N){
        vector<int>factorial;
        factorial.push_back(1);
        int carry;
        for(int i=2;i<=N;i++){
            carry=0;
            for(int j=0;j<factorial.size();j++){
                int num=factorial[j]*i+carry;
                int rem=num%10;
                factorial[j]=rem;
                carry=num/10;
            }
            while(carry!=0){
                int rem=carry%10;
                factorial.push_back(rem);
                carry=carry/10;
            }
        }
        reverse(factorial.begin(), factorial.end());
        return factorial;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends