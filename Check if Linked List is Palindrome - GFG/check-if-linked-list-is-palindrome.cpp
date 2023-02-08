//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    
    bool isPalindrome(Node *head)
    {
        int count=0;
        Node* prev=NULL;
        Node* temp=head;
        while(temp){
            count++;
            temp=temp->next;
        }
        
        Node* temp1=head;
        int i=1;
        while(i<=count/2){
            temp=temp1->next;
            temp1->next=prev;
            prev=temp1;
            temp1=temp;
            i++;
        }
        if(count%2==1){
            temp=temp1->next;
        }
        else{
            temp=temp1;
        }
        while(prev){
            if(prev->data==temp->data){
                prev=prev->next;
                temp=temp->next;
            }
            else{
                return false;
            }
        }
        return true;
        
        
        
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends