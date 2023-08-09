//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int n){
        int largest_prime = -1;
        int i = 2;
        while (i * i <= n) {
        while (n % i == 0) {
            largest_prime = i;
            n = n / i;
        }
        i = i + 1;
    }
    if (n > 1) {
        largest_prime = n;
    }
    return largest_prime;

    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends