//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void solvePush(stack<int>&s,int top){
        if(s.empty()){
            s.push(top);
            return;
        }
        if(s.top()<=top){
            s.push(top);
            return;
        }
        int top1=s.top();
        s.pop();
        solvePush(s,top);
        s.push(top1);
}
    
void solveSort(stack<int> &s){
        if(s.empty()){
            return;
        }
        int top=s.top();
        s.pop();
        solveSort(s);
        solvePush(s,top);
    }
void SortedStack :: sort()
{
    solveSort(s);
    // if(s.empty()){
    //         return;
    //     }
    //     int top=s.top();
    //     s.pop();
    //     sort();
    //     solvePush(s,top);
}



