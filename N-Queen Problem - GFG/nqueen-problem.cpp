//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
bool com(const vector<int>& a, const vector<int>& b) {
    if (a.size() == b.size()) {
        return std::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
    }
    return a.size() < b.size();
}
class Solution{
public:
bool isSafe(int row,int col,vector<vector<int>>&tChessBoard,int n,map<int,bool> &m1,map<int,bool> &m2,map<int,bool> &m3){
    if(m1[row]==1)
    {
        return false;
    }
    if(m2[row+col]==1)
    {
        return false;
    }
    if(m3[n-1+col-row]==1)
    {
        return false;
    }
    return true;
}
void pushInFCB(vector<vector<int>> &fChessBoard,vector<vector<int>>&tChessBoard,int n){
    vector<int>tans;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(tChessBoard[i][j]>0){
                // cout<<tChessBoard[i][j];
                tans.push_back(tChessBoard[i][j]);
            }
        }
    }
    fChessBoard.push_back(tans);
}
void solve(vector<vector<int>> &fChessBoard,vector<vector<int>>&tChessBoard,int n,int col,map<int,bool> &m1,map<int,bool> &m2,map<int,bool> &m3 ){
    if(col==n){
        pushInFCB(fChessBoard,tChessBoard,n);
        return;
    }
    for(int i=0;i<n;i++){
        if(isSafe(i,col,tChessBoard,n,m1,m2,m3)){
            tChessBoard[i][col]=col+1;
            m1[i]=1;
            m2[i+col]=1;
            m3[n-1+col-i]=1;
            solve(fChessBoard,tChessBoard,n,col+1,m1,m2,m3);
            tChessBoard[i][col]=0;
            m1[i]=0;
            m2[i+col]=0;
            m3[n-1+col-i]=0;
            
        }
    }
}
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>>fChessBoard;
        vector<vector<int>>tChessBoard(n,vector<int>(n,0));
        map<int,bool>m1;
        map<int,bool>m2;
        map<int,bool>m3;
        solve(fChessBoard,tChessBoard,n,0,m1,m2,m3);
        sort(fChessBoard.begin(),fChessBoard.end(),com);
        return fChessBoard;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends