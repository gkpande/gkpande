//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  void findNextSmaller(vector<int>&histogram,vector<int>&nextSmallerArray){
      int n=histogram.size();
      stack<int>st;
      st.push(-1);
      for(int i=n-1;i>=0;i--){
          while(st.top()!=-1 && histogram[st.top()]>=histogram[i]){
              st.pop();
          }
          nextSmallerArray[i]=st.top();
          st.push(i);
      }
  }
  void findPrevSmaller(vector<int>&histogram,vector<int>&prevSmallerArray){
      int n=histogram.size();
      stack<int>st;
      st.push(-1);
      for(int i=0;i<n;i++){
          while(st.top()!=-1 && histogram[st.top()]>=histogram[i]){
              st.pop();
          }
          prevSmallerArray[i]=st.top();
          st.push(i);
      }
  }
  int rectangelArea(vector<int>&histogram){
      //find nextsmaller
      vector<int>nextSmallerArray(histogram.size(),0);
      findNextSmaller(histogram,nextSmallerArray);
      //find prevsmaller
      vector<int>prevSmallerArray(histogram.size(),0);
      findPrevSmaller(histogram,prevSmallerArray);
      //if -1 in next smaller replace with m
      for(int i=0;i<nextSmallerArray.size();i++){
          if(nextSmallerArray[i]==-1){
              nextSmallerArray[i]=nextSmallerArray.size();
          }
      }
      //calculate area
      int largestArea=INT_MIN;
      for(int i=0;i<histogram.size();i++){
          int l=histogram[i];
          int w=nextSmallerArray[i]-prevSmallerArray[i]-1;
          int area=l*w;
          largestArea=max(largestArea,area);
      }
      return largestArea;
  }
    int maxArea(int M[MAX][MAX], int n, int m) {
        int maxArea=INT_MIN;
        //create Histogram for each row
        vector<int>histogram(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]==0){
                    histogram[j]=0;
                }
                else{
                    histogram[j]++;
                }
            }
            //on row histogram calulated now find largest histogram arear for that row.
            maxArea=max(maxArea,rectangelArea(histogram));
        }
        return maxArea;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends