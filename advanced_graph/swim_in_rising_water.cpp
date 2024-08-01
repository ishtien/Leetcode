#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> hmap;
        hmap.push({grid[0][0], 0, 0});
        
        while (!hmap.empty()) {
            auto top = hmap.top();
            int time = top[0];
            int row = top[1];
            int col = top[2];
            hmap.pop();
            
            if (row == rows - 1 && col == cols - 1) return time;
            
            if (visited[row][col]) continue;
            visited[row][col] = true;
            
            for (auto &dir : directions) {
                int x = row + dir[0];
                int y = col + dir[1];
                if (x >= 0 && x < rows && y >= 0 && y < cols && !visited[x][y]) {
                    hmap.push({max(time, grid[x][y]), x, y});
                }
            }
        }
        
        return -1; // This line should be unreachable.
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<vector<int>> grid = {
        {0, 2, 4},
        {2, 3, 6},
        {4, 6, 8}
    };

    int result = sol.swimInWater(grid);
    cout << "The minimum time required to swim from top-left to bottom-right is: " << result << endl;

    return 0;
}
