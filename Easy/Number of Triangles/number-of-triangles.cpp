//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        int numberOfTriangles(vector<vector<int>> &graph,int V)
        {
            int count_Triangle = 0;
 
            // Consider every possible
            // triplet of edges in graph
            for (int i = 0; i < V; i++)
            {
                for (int j = 0; j < V; j++)
                {
                    for (int k = 0; k < V; k++)
                     {
                        // Check the triplet if
                        // it satisfies the condition
                        if (graph[i][j] && graph[j][k]&& graph[k][i] && i!=j && j!=k && k!=i)
                            count_Triangle++;
                    }
                }
            }
 
    //     // If graph is directed ,
    // // division is done by 3,
    // // else division by 6 is done
    // isDirected? count_Triangle /= 3 :
                count_Triangle /= 3;
 
    return count_Triangle;

        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> g(n,vector<int> (n));
        for(auto &j:g)
            for(auto &i:j)
                cin>>i;
        Solution s;
        cout<<s.numberOfTriangles(g,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends