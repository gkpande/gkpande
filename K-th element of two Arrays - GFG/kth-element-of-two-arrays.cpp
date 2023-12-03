//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int approach1st(int arr1[], int arr2[], int n, int m, int k){
        //use merge procedure till k
        int i=0,j=0,ans;
        while(i<n && j<m){
            if(k==0){
                break;
            }
            if(arr1[i]<arr2[j]){
                ans=arr1[i];
                i++;
            }
            else{
                ans=arr2[j];
                j++;
            }
            k--;
            
        }
        while(i<n){
            if(k==0){
                break;
            }
            ans=arr1[i];
            
            i++;
            k--;
        }
        while(j<m){
            if(k==0){
                break;
            }
            ans=arr2[j];
            
            j++;
            k--;
        }
        return ans;
    }
    int approach2nd(int arr1[], int arr2[], int n, int m, int k,int st1,int st2){
        //if 1st array is over
        if(st1==n){
            return arr2[st2+k-1];
        }
        //if 2nd array is over
        if(st2==m){
            return arr1[st1+k-1];
        }
        if(k==1){
            return min(arr1[st1],arr2[st2]);
        }
        int mid=k/2;
        //mid lies out side of arr1.
        if(mid-1>=n-st1){
            if(arr1[n-1]>=arr2[mid-1]){
                return approach2nd(arr1,arr2,n,m,k-mid,st1,st2+mid);
            }
            else{
                return arr2[st2+k-n+st1-1];
            }
        }
        //mid lies out side of arr1.
        if(mid-1>=m-st2){
            if(arr2[m-1]>=arr1[mid-1]){
                return approach2nd(arr1,arr2,n,m,k-mid,st1+mid,st2);
            }
            else{
                return arr1[st1+k-m+st2-1];
            }
        }
        else{
            if(arr1[st1+mid-1]>arr2[st2+mid-1]){
                return approach2nd(arr1,arr2,n,m,k-mid,st1,st2+mid);
            }
            else{
                return approach2nd(arr1,arr2,n,m,k-mid,st1+mid,st2);
            }
        }
    }
    int effApproach(int arr1[], int arr2[], int n, int m, int k){
        if(n>m){
            return effApproach(arr2,arr1,m,n,k);
        }
        int low=max(0,k-m);
        int high=min(n,k);
        
        while(low<=high){
            int mid=low+(high-low)/2;
            int cut1=mid;
            int cut2=k-mid;
            int l1= cut1==0?INT_MIN:arr1[cut1-1];
            int l2= cut2==0?INT_MIN:arr2[cut2-1];
            int r1= cut1==n?INT_MAX:arr1[cut1];
            int r2= cut2==m?INT_MAX:arr2[cut2];
            if(l1<=r2 && l2<=r1){
                return max(l1,l2);
            }
            else if(l1>r2){
                high=cut1-1;
            }
            else{
                low=cut1+1;
            }
        }
    }
    
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        //efficient approach
        return effApproach(arr1,arr2,n,m,k);
        // return approach1st(arr1,arr2,n,m,k);//time O(k) ,space O(1)
        return approach2nd(arr1,arr2,n,m,k,0,0);//time O(logk) ,space O(1)
    }
};


//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends