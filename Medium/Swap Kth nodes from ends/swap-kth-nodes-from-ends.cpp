//{ Driver Code Starts
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp){
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
        
    bool f=true;
    
    for(int i=0; i<num; i++){
        if((i==K-1) || (i==num - K)){
            if(!((before[K-1] == after[num - K]) && (before[num-K] == after[K-1]))) f=0;
        }
        else{
            if(before[i] != after[i]) f=0;
        }
    }
    
    return f;
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, K , firstdata;
        cin>>num>>K;
        int temp;
        cin>>firstdata;
        Node* head = new Node(firstdata);
        Node* tail = head;
        for(int i = 0; i<num - 1; i++){
            cin>>temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }
        
        Node *before[num];
        addressstore(before, head);
        
        head = swapkthnode(head, num, K);
        
        Node *after[num];
        addressstore(after, head);
        
        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}

// } Driver Code Ends


//User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/

//Function to swap Kth node from beginning and end in a linked list.
Node *swapkthnode(Node* head, int n, int k)
{
    if(k>n){
        return head;
    }
    //if begin and end node are same then return same list.
    if(k==(n-k+1)){
        return head;
    }
    Node* beg=head;
    Node* end=head;
    Node* prev_beg=NULL;
    Node* prev_end=NULL;
    for(int i=1;i<k;i++){
        prev_beg=beg;
        beg=beg->next;
    }
    for(int i=1;i<n-k+1;i++){
        prev_end=end;
        end=end->next;
    }
    if(prev_beg!=NULL){
        prev_beg->next=end;
    }
    if(prev_end!=NULL){
        prev_end->next=beg;
    }
    Node* temp=beg->next;
    beg->next=end->next;
    end->next=temp;
    if(k==1){
        return head=end;
    }
    if(k==n){
        return head=beg;
    }
    return head;
}
