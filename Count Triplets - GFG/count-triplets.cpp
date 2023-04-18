//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void push(struct Node** head_ref, int new_data)
{
   
    struct Node* new_node = new Node(new_data);
    
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
} 

int countTriplets(struct Node* head, int x) ;

/* Driver program to test count function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n , x ,i , num;
        struct Node *head = NULL;
        cin>>n>>x;
        for(i=0;i<n;i++)
        {
            cin>>num;
            push(&head,num);
        }
 
    /* Check the count function */
    cout <<countTriplets(head, x)<< endl;
    }
    return 0;
}
// } Driver Code Ends


//User function Template for C++
struct node {
    int data;
    struct node* next, *prev;
};
int countTriplets(struct Node* head1, int x) 
{ 
    node* head=new node();
    head->data=head1->data;
    head->next=NULL;
    head->prev=NULL;
    Node* temp=head1->next;
    node* temp1=head;
    while(temp){
        temp1->next=new node();
        temp1->next->data=temp->data;
        temp1->next->prev=temp1;
        temp1->next->next=NULL;
        temp1=temp1->next;
        temp=temp->next;
        
    }
    node* lastNode=head;
    while(lastNode->next){
        lastNode=lastNode->next;
    }
    int count=0;
   node* currNode=head;
//   cout<<lastNode->prev->data<<currNode->next->data;
  while(currNode->next->next->data!=lastNode->data){
      node* first=currNode->next;
      node* last=lastNode;
      while(first->data< last->data){
            if(last->data+first->data==x-currNode->data){
                count++;
                first=first->next;
                last=last->prev;
            }
            else if(last->data+first->data<x-currNode->data){
                first=first->next;
            }
            else{
                last=last->prev;
            }
        }
        currNode=currNode->next;
  }
return count;
} 