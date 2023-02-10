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
        cout << node->data; 
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

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        int carry=0;
        
        
        Node* prev=NULL;
        Node* temp=head;
        while(temp!=NULL){
            Node* temp1=temp->next;
            temp->next=prev;
            prev=temp;
            temp=temp1;
        }
        temp=prev;
        
        int val=temp->data;
    
        temp->data=(val+1)%10;
        
        carry=(val+1)/10;
        
        Node* prev1 = temp;
        temp=temp->next;
        
        while(carry!=0 && temp!=NULL){
            val=temp->data;
            
            
            temp->data=(carry+val)%10;
            carry=(val+carry)/10;
            
            
            
            prev1 = temp;
            temp=temp->next;
        }
        //cout<<prev1->data;
        if(carry && temp==NULL){
            prev1->next=new Node(carry);
            prev1=prev1->next;
        }
        
        head=prev;
        prev=NULL;
        temp=head;
        while(temp){
            Node* temp1=temp->next;
            temp->next=prev;
            prev=temp;
            temp=temp1;
        }
        
        return prev;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends