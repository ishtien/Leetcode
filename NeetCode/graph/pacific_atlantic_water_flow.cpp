#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        unordered_set<int> pacific;
        unordered_set<int> atlantic;
        vector<vector<int>> res;
        for(int i = 0; i < m; i ++) {
            dfs(i, 0, m, n, 0, heights, pacific);
            dfs(i, n - 1, m, n, 0, heights, atlantic);
        }
        for(int i = 0; i < n; i ++) {
            dfs(0, i, m, n, 0, heights, pacific);
            dfs(m - 1, i, m, n, 0, heights, atlantic);
        }
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j++) {
                if(pacific.count(i*n + j ) && atlantic.count(i*n + j)) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
    void dfs(int row, int col, int m, int n, int height, vector<vector<int>>& heights, unordered_set<int>& ocean) {
        if(row < 0 || col < 0 || row >= m || col >=n || height > heights[row][col]|| ocean.count(row*n + col)) return;
        ocean.insert(row*n + col);
        dfs(row + 1, col, m, n, heights[row][col], heights, ocean);
        dfs(row - 1, col, m, n, heights[row][col], heights, ocean);
        dfs(row, col + 1, m, n, heights[row][col], heights, ocean);
        dfs(row, col - 1, m, n, heights[row][col], heights, ocean);
    }
};

int main() {
    // Example heights matrix
    vector<vector<int>> heights = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}
    };

    // Create an instance of the Solution class
    Solution sol;

    // Call the pacificAtlantic method
    vector<vector<int>> result = sol.pacificAtlantic(heights);

    // Output the result
    cout << "Resulting coordinates: " << endl;
    for (const auto& coord : result) {
        cout << "(" << coord[0] << ", " << coord[1] << ")" << endl;
    }

    return 0;
}
