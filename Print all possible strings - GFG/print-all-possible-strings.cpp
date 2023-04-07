//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

vector<string>  spaceString(char str[]);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        char str[10000];
        cin>>str;
        vector<string> vec = spaceString(str);
        for(string s: vec){
            cout<<s<<"$";
        }
        cout<<endl;
    }

}

// } Driver Code Ends


void solve(char str[],vector<string>&res,string s,int i,int len){
    if(i==len-1){
        s+=str[i];
        res.push_back(s);
        return;
    }
    solve(str,res,s+str[i],i+1,len);
    solve(str,res,s+str[i]+" ",i+1,len);
}


vector<string>spaceString(char str[])
{
    string s="";
    int len = 0;
    for(int i=0;str[i]!='\0';i++){
        len+=1;
    }
    
    
    vector<string>res;
    solve(str,res,s,0,len);
    return res;


}