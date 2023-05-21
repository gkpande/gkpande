//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

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

class Solution{
    public:
    bool areAnagrams(Node *root1, Node *root2)
    {
        //anagram: each level having same character with same frequency
        //traverse each level and check they are same or not.
        if(root1==NULL && root2 == NULL){
            return true;
        }
        if(root1==NULL || root2==NULL){
            return false;
        }
        //declare queue for level order traversal
        queue<Node *>q1;//for 1st tree
        queue<Node *>q2;//for 2nd tree
        q1.push(root1);
        q2.push(root2);
        while(!q1.empty() && !q2.empty()){
            int size1=q1.size();
            int size2=q2.size();
            if(size1!=size2){
                return false;
            }
            vector<int>level1;
            vector<int>level2;
            while(size1>0){             //store each level in level1
                Node* front=q1.front();
                q1.pop();
                if(front->left){
                    q1.push(front->left);
                }
                if(front->right){
                    q1.push(front->right);
                }
                level1.push_back(front->data);
                size1--;
            }
            while(size2>0){             //store each level in level2
                Node* front=q2.front();
                q2.pop();
                if(front->left){
                    q2.push(front->left);
                }
                if(front->right){
                    q2.push(front->right);
                }
                level2.push_back(front->data);
                size2--;
            }
            //compare level1 and level2
            sort(level1.begin(),level1.end());
            sort(level2.begin(),level2.end());
            for(int i=0;i<level1.size();i++){
                if(level1[i]!=level2[i]){
                    return false;
                }
            }
        }
        return true;
    
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node *root1 = buildTree(treeString1);
        getline(cin, treeString2);
        Node *root2 = buildTree(treeString2);
        Solution ob;
        cout << ob.areAnagrams(root1, root2) << endl;
    }
    return 0;
}

// } Driver Code Ends