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
        Node* firstHead=NULL;
        Node* secondHead=NULL;
        Node* thirdHead=NULL;
        Node* temp=head;
        Node* fs=NULL;
        Node* sh=NULL;
        Node* th=NULL;
        while(temp){
            if(temp->data==0){
                if(firstHead==NULL){
                    firstHead=temp;
                    fs=firstHead;
                }
                else{
                    fs->next=temp;
                    fs=fs->next;
                    
                }
            }
            else if(temp->data==1){
                if(secondHead==NULL){
                    secondHead=temp;
                    sh=secondHead;
                }
                else{
                    sh->next=temp;
                    sh=sh->next;
                }
            }
            else{
                if(thirdHead==NULL){
                    thirdHead=temp;
                    th=thirdHead;
                }
                else{
                    th->next=temp;
                    th=th->next;
                    
                }
            }
            temp=temp->next;
        }
        if(fs){
            fs->next=NULL;
        }
        if(sh){
            sh->next=NULL;
        }
        if(th){
             th->next=NULL;
        }
       
        if(fs!=NULL && sh!=NULL && th!=NULL){
            fs->next=secondHead;
            sh->next=thirdHead;
            return firstHead; 
        }
        else if(sh!=NULL && th!=NULL){
            sh->next=thirdHead;
            return secondHead;
        }
        else if(fs!=NULL && th!=NULL){
            fs->next=thirdHead;
            return firstHead;
        }
        else if(sh!=NULL && fs!=NULL){
            fs->next=secondHead;
            return firstHead;
        }
        else if(fs!=NULL){
            return firstHead;
        }
        else if(sh!=NULL){
            return secondHead;
        }
        else{
            return thirdHead;
        }
       
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