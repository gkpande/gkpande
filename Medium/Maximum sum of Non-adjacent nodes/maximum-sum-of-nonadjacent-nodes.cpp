//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
//User function Template for C++

//Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    int calltograndchild(Node* root,unordered_map<Node*,int>&mem){
        if(root==NULL){
            return 0;
        }
        // if(root->left==NULL && root->right==NULL){
        //     return  root->data;
        // }
        int sum=0;
        if(root->left){
            sum=sum+solveMem(root->left->left,mem)+solveMem(root->left->right,mem);
        }
        if(root->right){
            sum=sum+solveMem(root->right->left,mem)+solveMem(root->right->right,mem);
        }
        return sum;
    }
    int calltochild(Node* root,unordered_map<Node*,int>&mem){
        if(root==NULL){
            return 0;
        }
        // if(root->left==NULL && root->right==NULL){
        //     return  root->data;
        // }
        int sum=0;
        sum=sum+solveMem(root->left,mem)+solveMem(root->right,mem);
        return sum;
    }
    // int solveRec(Node* root){
    //     if(root==NULL){
    //         return 0;
    //     }
    //     //if root chossen
    //     int incl=0;
    //     incl=root->data+calltograndchild(root,);
    //     int excl=0+calltochild(root);
    //     return max(incl,excl);
    // }
    int solveMem(Node* root,unordered_map<Node*,int>&mem){
        if(root==NULL){
            return 0;
        }
        if(mem.find(root)!=mem.end()){
            return mem[root];
        }
        //if root chossen
        int incl=0;
        incl=root->data+calltograndchild(root,mem);
        int excl=0+calltochild(root,mem);
        mem[root]=max(incl,excl);
        return mem[root];
    }
    pair<int,int> solveRec(Node* root){
        if(root==NULL){
            pair<int,int>p=make_pair(0,0);
            return p;
        }
        pair<int,int> l=solveRec(root->left);
        pair<int,int> r=solveRec(root->right);
        return {root->data+l.second+r.second,max(l.first,l.second)+max(r.first,r.second)};
    }
    int getMaxSum(Node *root) 
    {
        // return solveRec(root);
        //memorization
        // unordered_map<Node*,int>mem;
        // return solveMem(root,mem);
        pair<int,int>ans=solveRec(root);
        return max(ans.first,ans.second);
    }
};

//{ Driver Code Starts.

// Driver code 
int main()
{
  int t;
  scanf("%d ",&t);
  while (t--)
  {
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		Solution ob;
        cout<<ob.getMaxSum(root)<<endl;
  }
  return 0;
}
// } Driver Code Ends