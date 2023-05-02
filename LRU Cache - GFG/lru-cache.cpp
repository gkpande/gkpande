//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way
class LRUCache
{
    
    public:
    class node{
        public:
        int key;
        int value;
        node* prev;
        node* next;
        node(int key,int val){
            this->key=key;
            this->value=val;
        }
    };
    int capacity;
    node * head=new node(-1,-1);
    node* tail=new node(-1,-1);
    private:
    unordered_map<int,node*>mp;
    public:
    LRUCache(int cap)
    {
        capacity=cap;
        head->next=tail;
        
        tail->prev=head;
       
    }
    void addnode(node* newnode){
        node* temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }
    void delnode(node * delnode){
        node* delprev=delnode->prev;
        node* delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        if(mp.find(key)!=mp.end()){
            node * newkey=mp[key];
            int res=newkey->value;
            mp.erase(key);
            delnode(newkey);
            addnode(newkey);
            mp[key]=head->next;
            
            return res;
        }
        else{
            return -1;
        }
        
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        if(mp.find(key)!=mp.end()){
             node * newkey=mp[key];
             mp.erase(key);
             delnode(newkey);
        }
        if(mp.size()==capacity){
            
            mp.erase(tail->prev->key);
            delnode(tail->prev);
        }
        node* newnode=new node(key,value);
        mp[key]=newnode;
        addnode(newnode);
        
    }
//     2
// 8
// SET 4 4 SET 3 3 SET 2 2 SET 1 1 GET 1 GET 2 GET 3 GET 4
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends