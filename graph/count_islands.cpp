#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == '1') {
                    count++;
                    dfs(i, j, rows, cols, grid);
                }
            }
        }
        return count;
    }
    
    void dfs(int row, int col, int m, int n, vector<vector<char>>& grid) {
        if(row < 0 || col < 0 || row >= m || col >= n || grid[row][col] == '0') return;
        grid[row][col] = '0'; // Mark as visited
        dfs(row + 1, col, m, n, grid);
        dfs(row - 1, col, m, n, grid);
        dfs(row, col + 1, m, n, grid);
        dfs(row, col - 1, m, n, grid);
    }
};

int main() {
    Solution sol;
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    
    int islands = sol.numIslands(grid);
    cout << "Number of islands: " << islands << endl;

    return 0;
}
