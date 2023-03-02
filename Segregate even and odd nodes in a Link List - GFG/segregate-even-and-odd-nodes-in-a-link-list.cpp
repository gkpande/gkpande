//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        Node* eNode=NULL;
        Node* oNode=NULL;
        Node *et=NULL;
        Node *ot=NULL;
        Node* temp=head;
        while(temp){
            if(temp->data%2==0){
                if(eNode==NULL){
                    eNode=temp;
                    et=temp;
                }
                else{
                    et->next=temp;
                    et=et->next;
                }
            }
            else{
                if(oNode==NULL){
                    oNode=temp;
                    ot=temp;
                }
                else{
                    ot->next=temp;
                    ot=ot->next;
                }
                
            }
            temp=temp->next;
        }
        if(oNode==NULL || eNode==NULL){
            return head;
        }
        et->next=oNode;
        ot->next=NULL;
        head=eNode;
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends