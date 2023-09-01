//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) 
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function template for C++

/*
struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution{
  public:
  void countPath(Node* root, int k,int &count,vector<int>path){
      if(root==NULL){
          return;
      }
      path.push_back(root->data);
      countPath(root->left,k,count,path);
      countPath(root->right,k,count,path);
      int sum=0;
      int n=path.size();
      for(int i=n-1;i>=0;i--){
          sum=sum+path[i];
          if(sum==k){
              count++;
          }
      }
      path.pop_back();
  }
  int solve(Node* root,int k,unordered_map<int,int>&mp,int sum){
      if(root==NULL){
          return 0;
      }
      int count=0;
      sum +=root->data;
      if(mp.find(sum-k)!=mp.end()){
          count +=mp[sum-k];
      }
      mp[sum]++;
      int l=solve(root->left,k,mp,sum);
      int r=solve(root->right,k,mp,sum);
      mp[sum]--;
      return count+l+r;
  }
    int sumK(Node *root,int k)
    {
        //  int count=0;
        //  vector<int>path;
        //  countPath(root,k,count,path);
        //  return count;
        //efficient approach
        unordered_map<int,int>mp;
        mp[0]++;
        return solve(root,k,mp,0);
    }
};


//{ Driver Code Starts.

int main() {
    string tc;
    getline(cin, tc);
    int t = stoi(tc);
  
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        string key;
        getline(cin, key);
        int k=stoi(key);
        Solution ob;
        cout << ob.sumK(root, k) << "\n";
    }
    return 0;
}
// } Driver Code Ends