//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};
class cmp{
    public:
    bool operator()(Node* a,Node* b){
        return a->data > b->data;
    }
};
class Solution
{
	public:
	void travers(Node* root,vector<string>&ans,string str){
	    if(root->left==NULL && root->right==NULL){
	        ans.push_back(str);
	        return;
	    }
	    travers(root->left,ans,str+'0');
	    travers(root->right,ans,str+'1');
	}
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		  //create a min heap
		  priority_queue<Node*,vector<Node*>,cmp>pq;
		  //put all element in min heap.
		  for(int i=0;i<N;i++){
		      Node* temp=new Node(f[i]);
		      pq.push(temp);
		  }
		  while(pq.size()>1){
		      //pop two minimum
		      Node* left=pq.top();
		      pq.pop();
		      Node* right=pq.top();
		      pq.pop();
		      Node* newNode=new Node(left->data + right->data);
		      newNode->left=left;
		      newNode->right=right;
		      pq.push(newNode);
		  }
		  Node* root=pq.top();
		  vector<string>ans;
		  string str="";
		  travers(root,ans,str);
		  return ans;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends