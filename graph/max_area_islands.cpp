#include <iostream>
#include <vector>
using namespace std;
class SolutionModify {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int max_area = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    int area = dfs(i, j, m, n, grid, area);
                    max_area = max(max_area, area);
                }
            }
        }
        return max_area;
    }
    int dfs(int row, int col, int m, int n, vector<vector<int>>& grid, int& count) {
        if(row < 0 || col < 0 || row >= m || col >= n || grid[row][col] == 0) return 0;
        count++;
        grid[row][col] = 0;
        return 1 + dfs(row + 1, col, m, n, grid, count) + dfs(row - 1, col, m, n, grid, count) + dfs(row, col + 1, m, n, grid, count) + dfs(row, col - 1, m, n, grid, count);
    }
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int max_area = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    int area = 0;
                    dfs(i, j, m, n, grid, area);
                    max_area = max(max_area, area);
                }
            }
        }
        return max_area;
    }
    
    void dfs(int row, int col, int m, int n, vector<vector<int>>& grid, int& count) {
        if(row < 0 || col < 0 || row >= m || col >= n || grid[row][col] == 0) return;
        count++;
        grid[row][col] = 0;
        dfs(row + 1, col, m, n, grid, count);
        dfs(row - 1, col, m, n, grid, count);
        dfs(row, col + 1, m, n, grid, count);
        dfs(row, col - 1, m, n, grid, count);
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };
    
    int max_area = sol.maxAreaOfIsland(grid);
    cout << "Maximum area of island: " << max_area << endl;

    return 0;
}
