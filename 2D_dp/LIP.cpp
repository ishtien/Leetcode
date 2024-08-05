#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int res = 0;
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        for(int i = 0; i < rows ; i++) {
            for(int j = 0; j < cols; j++) {
                res = max(res, dfs(matrix, rows, cols, i, j, -1, dp)); //bigger
            }
        }
        return res;
        
    }
    int dfs(vector<vector<int>>& matrix, int rows, int cols, int r, int c, int prevValue, vector<vector<int>>&dp) {
        if(r >= rows || c >= cols || r < 0 || c < 0 || prevValue >= matrix[r][c]) return 0;
        if(dp[r][c]) return dp[r][c];
        int res = 0;
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(auto &dir : directions) {
            int x = r + dir[0];
            int y = c + dir[1];
            res = max(res, dfs(matrix, rows, cols, x, y, matrix[r][c], dp));
        }
        dp[r][c] = res + 1;
        return dp[r][c];
    }
};


int main() {
    Solution solution;

    // Test case 1
    vector<vector<int>> matrix1 = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };
    cout << "Test case 1: " << solution.longestIncreasingPath(matrix1) << endl;

    // Test case 2
    vector<vector<int>> matrix2 = {
        {3, 4, 5},
        {3, 2, 6},
        {2, 2, 1}
    };
    cout << "Test case 2: " << solution.longestIncreasingPath(matrix2) << endl;

    // Test case 3
    vector<vector<int>> matrix3 = {
        {1}
    };
    cout << "Test case 3: " << solution.longestIncreasingPath(matrix3) << endl;

    // Test case 4
    vector<vector<int>> matrix4 = {
        {1, 2},
        {4, 3}
    };
    cout << "Test case 4: " << solution.longestIncreasingPath(matrix4) << endl;

    // Test case 5
    vector<vector<int>> matrix5 = {
        {5, 5, 3},
        {2, 3, 6},
        {1, 1, 1}
    };
    cout << "Test case 5: " << solution.longestIncreasingPath(matrix5) << endl;

    return 0;
}
