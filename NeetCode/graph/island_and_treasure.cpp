#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class SolutionModify {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < m ; i++) {
            for(int j = 0; j < n; j ++) {
                if(grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto front = q.front();
                vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                for (auto &dir : directions) {
                    int x = front.first + dir.first;
                    int y = front.second + dir.second;
                    if(x < 0 || y < 0 || x >= m || y >= n || grid[x][y] !=INT_MAX) continue;
                    q.push({x, y});
                    grid[x][y] = min(grid[x][y], grid[front.first][front.second] + 1);
                    
                }
                q.pop();
            }
        } 
    }
};

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m ; i++) {
            for(int j = 0; j < n; j ++) {
                if(grid[i][j] == 0) {
                    vector<vector<bool>> visited(m, vector<bool>(n, false));
                    bfs(i, j, grid, m, n, 0, visited);
                }
            }
        }

    }
    void bfs(int row, int col, vector<vector<int>>& grid, int m, int n, int count, vector<vector<bool>>& visited) {
        queue<pair<int, int>> q;

        q.push({row, col});

        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto front = q.front();
                vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                for (auto &dir : directions) {
                    int x = front.first + dir.first;
                    int y = front.second + dir.second;
                    if(x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == -1 || visited[x][y]) continue;
                    q.push({x, y});
                    
                }
                visited[front.first][front.second] = true;
                grid[front.first][front.second] = min(count, grid[front.first][front.second]);
                q.pop();
                
            }
            count ++ ;
        } 
    }
};


int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {2147483647,-1,0,2147483647},
        {2147483647,2147483647,2147483647,-1},
        {2147483647,-1,2147483647,-1},
        {0,-1,2147483647,2147483647}
    };

    sol.islandsAndTreasure(grid);

    // Print the modified grid
    cout << "Modified Grid:" << endl;
    for (const auto& row : grid) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
