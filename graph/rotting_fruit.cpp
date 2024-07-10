#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int time = 0;
        int fresh = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        while(fresh > 0 && !q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i ++) {
                auto front = q.front();
                int row = front.first;
                int col = front.second;
                vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                for(auto &dir: directions) {
                    int x = row + dir.first;
                    int y = col + dir.second;
                    if(x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 0 || grid[x][y] == 2) continue;
                    q.push({x, y});
                    grid[x][y] = 2;
                    fresh--;
                }
                q.pop();
            }
            time++;
        }
        return (fresh == 0)?time:-1;
    }
};


int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    Solution sol;
    int result = sol.orangesRotting(grid);

    cout << "Result: " << result << endl;

    return 0;
}
