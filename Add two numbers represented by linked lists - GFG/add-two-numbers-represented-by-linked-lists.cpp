//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    struct Node* reverse(struct Node* head){
        struct Node* prev=NULL;
        struct Node* temp=head;
        while(temp){
            struct Node* temp1=temp->next;
            temp->next=prev;
            prev=temp;
            temp=temp1;
        }
        return prev;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        struct Node * head1=reverse(first);
        
        struct Node * head2=reverse(second);
        // cout<<head2->data<<head2->next->data<<head2->next->next->data;
        struct Node * h1= head1;
        struct Node * h2 =head2;
        int carry=0;
        struct Node * prev1=NULL;
        struct Node * prev2=NULL;
        while(h1 && h2){
            int val=h1->data+h2->data+carry;
            h1->data=val%10;
            carry=val/10;
            prev1=h1;
            prev2=h2;
            h1=h1->next;
            h2=h2->next;
        }
        
        while(h2){
            int val=h2->data+carry;
            prev1->next=new Node(val%10);
            carry=val/10;
            prev1=prev1->next;
            prev2=h2;
            h2=h2->next;
        }
        while(h1){
            int val=h1->data+carry;
            h1->data=val%10;
            carry=val/10;
            prev1=h1;
            h1=h1->next;
        }
        if(carry==1){
            prev1->next=new Node(carry);
            prev1=prev1->next;
        }
        return reverse(head1);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends