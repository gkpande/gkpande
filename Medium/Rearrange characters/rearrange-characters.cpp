//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends
class Solution
{
    public:
    string rearrangeString(string str)
    {
        int len=str.length();
        //create a frequency array 
        int freqArr[26]={0};
        //fill the frequency array with frequency of each char
        for(int i=0;i<len;i++){
            freqArr[str[i]-'a']++;
        }
        //fill even postion element with maxmimum frequency
        //find max frequency char with there freq
        int maxFreq=0;
        char maxCharfreq;
        for(int i=0;i<26;i++){
            if(freqArr[i]>maxFreq){
                maxFreq=freqArr[i];
                maxCharfreq='a'+i;
            }
        }
        // cout<<maxFreq<<maxCharfreq;
        // char ptr[len];
        string ptr(len, ' ');
        
        // if maxfreq>len than cant be arrange
        if(maxFreq>((len+1)/2)){
            return "-1";
        }
        //fill result arr wiith even position first with max freq char.
        int i=0;
        while(maxFreq>0){
            ptr[i]=maxCharfreq;
            i+=2;
            maxFreq--;
        }
        freqArr[maxCharfreq-'a']=0;
        //if any even postion left
        for(int j=0;j<26;j++){
            while(freqArr[j]>0){
                i=(i>=len)?1:i;
                ptr[i]='a'+j;
                freqArr[j]--;
                i+=2;
            }
        }
        return ptr;
    }
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}
// } Driver Code Ends