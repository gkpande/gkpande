//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* inputList(int size)
{
    if (size == 0) return NULL;

    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}


// } Driver Code Ends
/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution
{
public:
    int intersectPoint(Node* head1, Node* head2)
    {
        int len1=0,len2=0;
        Node* temp=head1;
        while(temp){
            len1++;
            temp=temp->next;
        }
        temp=head2;
        while(temp){
            len2++;
            temp=temp->next;
        }
    
    if(len1==0||len2==0){
        return -1;
    }
    if(len1>len2){
        temp=head1;
        while(len1!=len2){
            len1--;
            temp=temp->next;
            
        }
        Node* temp1=head2;
        while(temp1!=temp){
            temp=temp->next;
            temp1=temp1->next;
        }
        return temp->data;
    }
    else{
        temp=head2;
        while(len1!=len2){
            len2--;
            temp=temp->next;
            
        }
        Node* temp1=head1;
        while(temp1 && temp && temp1!=temp){
            temp=temp->next;
            temp1=temp1->next;
        }
        if(temp){
            return temp->data;
        }
        else{
            return -1;
        }
        
        
    }
    return -1;
    }
};



//{ Driver Code Starts.


/* Driver program to test above function*/
int main()
{
    int T, n1, n2, n3;

    cin >> T;
    while (T--)
    {
        cin >> n1 >> n2 >> n3;

        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);

        Node* temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;
        
        Solution ob;
        cout << ob.intersectPoint(head1, head2) << endl;
    }
    return 0;
}


// } Driver Code Ends