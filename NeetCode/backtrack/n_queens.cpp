#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        int queen_count = n;
        vector<string> board(n, string(n, '.'));
        dfs(0, board, n, res);
        return res;
    }
    
    void dfs(int row, vector<string>& board, int n, vector<vector<string>>& res) {
        if(row == n) {
            res.push_back(board);
            return;
        }
        int rows = board.size();
        int cols = board[0].size();
        
        for(int i = 0; i < n; i ++ ) {
            if(isValid(row, i, board, n)) {
                board[row][i] = 'Q';
                dfs(row + 1, board, n, res);
                board[row][i] = '.';
            }
        }
        return;
    }
    
    bool isValid(int row, int col, vector<string>& board, int n) {
        int rows = board.size();
        int cols = board[0].size();
        for(int i = 0; i < n; i++) {
            if(i != col && board[row][i] == 'Q') return false;
        }
        for(int i = 0; i < n; i++) {
            if(i != row && board[i][col] == 'Q') return false;
        }
        for(int i = 1; i <= row; i++) {
            if(row - i >= 0 && col - i >= 0 && board[row - i][col - i] == 'Q') return false;
        }
        for(int i = 0; i <= row ; i++) {
            if(col + i <= cols && row - i >= 0 && board[row - i][col + i] == 'Q') return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    int n = 4; // 測試4皇后問題
    vector<vector<string>> result = sol.solveNQueens(n);

    // 輸出結果
    for(const auto& solution : result) {
        cout << "Solution:" << endl;
        for(const string& row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
