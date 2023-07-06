//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        unordered_set<int>st;
        unordered_map<int,int>mp;
        int pagefault=0;
        for(int i=0;i<N;i++){
            if(st.size()<C){
                if(st.find(pages[i])==st.end()){
                    st.insert(pages[i]);
                    pagefault++;
                }
                
                mp[pages[i]]=i;
                
            }
            else if(st.find(pages[i])!=st.end()){
                mp[pages[i]]=i;
            }
            else{
                int lru=INT_MAX;
                int val;
                for(auto itr:st){
                    if(mp[itr]<lru){
                        lru=mp[itr];
                        val=itr;
                    }
                }
                st.erase(val);
                st.insert(pages[i]);
                pagefault++;
                mp[pages[i]]=i;
            }
        }
        return pagefault;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}
// } Driver Code Ends