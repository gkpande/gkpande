//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class disjointSet {
public:
    vector<int> parent;
    vector<int> rank;

    disjointSet(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        rank.resize(n, 0);
    }

    int findUlp(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findUlp(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUlp(u);
        int ulp_v = findUlp(v);
        if (ulp_u == ulp_v) {
            return;
        }
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int n = accounts.size();
        disjointSet ds(n);
        // Create a map mail to index
        unordered_map<string, int> mailToIndex;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (mailToIndex.find(accounts[i][j]) == mailToIndex.end()) {
                    mailToIndex[accounts[i][j]] = i;
                } else {
                    ds.unionByRank(i, mailToIndex[accounts[i][j]]);
                }
            }
        }

        // Create merged accounts
        vector<vector<string>> mergedAccount(n);

        for (auto it : mailToIndex) {
            int index = it.second;
            string mail = it.first;
            int ulp = ds.findUlp(index);
            mergedAccount[ulp].push_back(mail);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (!mergedAccount[i].empty()) {
                string name = accounts[i][0];
                sort(mergedAccount[i].begin(), mergedAccount[i].end());
                vector<string> temp;
                temp.push_back(name);
                for (auto it : mergedAccount[i]) {
                    temp.push_back(it);
                }
                ans.push_back(temp);
            }
        }

        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends