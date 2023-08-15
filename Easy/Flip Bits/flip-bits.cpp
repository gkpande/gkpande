//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        int maxCount=0;
        int count = 0;
        int countOne = 0;
        for(int i=0;i<n;i++){
            if(a[i]==1){
                countOne++; //count number of 1's
            }
            if(a[i]==0){ 
                count++; //count of flips required
            }else{
                count--; //if element is 1 then it should be zero and not to be counted in the flip's count or in the result
            }
            if(count>0 && count > maxCount){
                maxCount = count;//update if count is maximum
            }else if(count<0){
                count = 0;// if negative count then discard
            }
        }
        return maxCount + countOne;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends