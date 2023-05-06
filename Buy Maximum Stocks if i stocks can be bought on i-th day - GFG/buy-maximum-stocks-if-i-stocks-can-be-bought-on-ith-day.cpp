//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
       vector<pair<int,int>>stockDay;
       for(int i=0;i<n;i++){
           stockDay.push_back({price[i],i+1});
       }
  
       sort(stockDay.begin(),stockDay.end());
        //   for(int i=0;i<stockDay.size()-1;i++){
        //     cout<<stockDay[i].first<<" "<<stockDay[i].second<<"-";
        // }
       int count=0;
       for(int i=0;i<n;i++){
           if(stockDay[i].first*stockDay[i].second<=k){
               count+=stockDay[i].second;
               k =k- stockDay[i].first*stockDay[i].second;
               
           }
           else {
               count += k/stockDay[i].first;
               k -= (k/stockDay[i].first * stockDay[i].first) ;
           }
           if(k==0){
               break;
           }
       }
       return count;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends