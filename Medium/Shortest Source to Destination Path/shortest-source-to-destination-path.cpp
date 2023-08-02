//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> visited(N, vector<int>(M, 0));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = 1;

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int i = curr.first;
            int j = curr.second;

            if (i == X && j == Y) {
                return visited[i][j] - 1; // Subtract 1 to get the distance from (0, 0) to (X, Y)
            }

            for (const auto& dir : directions) {
                int x = i + dir[0];
                int y = j + dir[1];

                if (x >= 0 && x < N && y >= 0 && y < M && A[x][y] == 1 && !visited[x][y]) {
                    q.push({x, y});
                    visited[x][y] = visited[i][j] + 1;
                }
            }
        }

        return -1; // Target (X, Y) is not reachable

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends