#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i ++) {
            dfs(i, 0, m, n, board);
            dfs(i, n-1, m, n, board);
        }
        for(int i = 0; i < n; i++) {
            dfs(0, i, m, n, board);
            dfs(m-1, i, m, n, board);
        }
        for(int i = 0; i < m ; i ++ ) {
            for(int j = 0; j < n; j++ ) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] =='Y') board[i][j] = 'O';
            }
        }
    }
    void dfs(int row, int col, int m, int n, vector<vector<char>>& board) {
        if(row < 0 || col < 0 || row >= m || col >= n || board[row][col] != 'O') return;
        board[row][col] = 'Y';
        dfs(row + 1, col, m, n, board);
        dfs(row - 1, col, m, n, board);
        dfs(row, col + 1, m, n, board);
        dfs(row, col - 1, m, n, board);
    }
};

int main() {
    // Example board
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    Solution solution;
    solution.solve(board);

    // Output the modified board
    cout << "Modified Board:" << endl;
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
