//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        //create a num array to store all permutation becasue each permutaion will start from 
        //any 1 to n
        vector<int>num;
        int fact=1;
        //finding factorial of n-1 num
        for(int i=1;i<n;i++){
            fact *=i;
            num.push_back(i);
        }
        num.push_back(n);
        k=k-1;
        string ans="";
        while(true){
            ans=ans+to_string(num[k/fact]);
            num.erase(num.begin()+k/fact);
            if(num.size()==0){
                break;
            }
            k=k%fact;
            fact=fact/num.size();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends