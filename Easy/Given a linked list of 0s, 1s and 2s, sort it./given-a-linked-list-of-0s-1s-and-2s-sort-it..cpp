//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // approach 1:count number of 0's and num of 1's and nums 2's replace tha data
        //approach 2: make the three list of 0's and 1's and 2's amd finally merge them.
        Node* head0=NULL;
        Node* head1=NULL;
        Node* head2=NULL;
        Node* h0=NULL;
        Node* h1=NULL;
        Node* h2=NULL;
        Node* thead=head;
        while(thead!=NULL){
            Node* temp=thead->next;
            if(thead->data==0){
                if(h0==NULL){
                    h0=thead;
                    h0->next=NULL;
                    head0=h0;
                }else{
                    h0->next=thead;
                    h0=h0->next;
                    h0->next=NULL;
                }
            }
            else if(thead->data==1){
                if(h1==NULL){
                    h1=thead;
                    h1->next=NULL;
                    head1=h1;
                }else{
                    h1->next=thead;
                    h1=h1->next;
                    h1->next=NULL;
                }
            }else{
                if(h2==NULL){
                    h2=thead;
                    h2->next=NULL;
                    head2=h2;
                }else{
                    h2->next=thead;
                    h2=h2->next;
                    h2->next=NULL;
                }
            }
            thead=temp;
        }
        if(h0!=NULL && h1!=NULL && h2!=NULL){
            h0->next=head1;
            h1->next=head2;
        }
        else if(h0!=NULL && h1!=NULL){
            h0->next=head1;
        }
        else if(h0!=NULL && h2!=NULL){
            h0->next=head2;
        }
        else if(h1!=NULL && h2!=NULL){
            h1->next=head2;
            return head1;
        }
        else if(h1!=NULL){
            return head1;
        }
        else if(h2!=NULL){
            return head2;
        }
        return head0;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends