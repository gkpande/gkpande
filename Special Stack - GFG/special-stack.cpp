//{ Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}
// } Driver Code Ends

int mini;
void push(stack<int>& s, int a){
    
	if(isEmpty(s)){
	    s.push(a);
	    mini=a;
	}
	else if(a<mini){
	    int val=2*a-mini;
	    s.push(val);
	     mini=a;
	}
	else{
	   
	   s.push(a);
	}
	
    
}

bool isFull(stack<int>& s,int n){
	if(s.size()==n){
	    return true;
	}
	return false;
}

bool isEmpty(stack<int>& s){
	
	    return s.empty();
	
	
}

int pop(stack<int>& s){
    if(isEmpty(s)){
        return -1;
    }
	int top=s.top();
	s.pop();
	if(top<mini){
	    int temp=mini;
	    mini=2*mini-top;
	    return temp;
	        
	}
	else{
	    return top;
	}
}

int getMin(stack<int>& s){
    if(isEmpty(s)){
        return -1;
    }
	return mini;
}