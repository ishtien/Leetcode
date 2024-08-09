#include <iostream>
#include <vector>
using namespace std;
class SolutionModify {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(i, j, board, word, 0))
                        return true;
                }
            }
        }
        return false;
        
    }
    bool dfs(int i, int j, vector<vector<char>>& board, string& word, int word_idx) {
        int rows = board.size();
        int cols = board[0].size();
        if(i < 0 || j < 0 || i >= rows || j >= cols || word[word_idx] != board[i][j]) return false;
        
        if(word[word_idx] == board[i][j]) {
            if(word_idx == word.size()-1) {
                board[i][j] = word[word_idx];
                return true;
            }
            board[i][j] = '#';
            vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
            for(auto &dir: directions) {
                int x = i + dir.first;
                int y = j + dir.second;

                if(dfs(x, y, board, word, word_idx + 1)) {
                    board[i][j] = word[word_idx];
                    return true;
                }
            }
        } 
        board[i][j] = word[word_idx];
        return false;

    }
};


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        bool isExisted = false;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                vector<vector<bool>> visited(rows, vector<bool>(cols, false));
                if(board[i][j] == word[0]) dfs(i, j, board, word, 0, isExisted, visited);
            }
        }
        return isExisted;
    }
    
    void dfs(int i, int j, vector<vector<char>>& board, string& word, int word_idx, bool& isExisted, vector<vector<bool>>& visited) {
        int rows = board.size();
        int cols = board[0].size();
        if(i < 0 || j < 0 || i >= rows || j >= cols || visited[i][j]) return;
        if(word[word_idx] == board[i][j]) {
            if(word_idx == word.size()-1) {
                isExisted = true;
                return;
            }
            visited[i][j] = true;
            vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
            for(auto &dir: directions) {
                int x = i + dir.first;
                int y = j + dir.second;
                dfs(x, y, board, word, word_idx + 1, isExisted, visited);
            }
            visited[i][j] = false; // Backtracking step
        }
    }
};

int main() {
    Solution sol;
    SolutionModify sol2;
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word1 = "ABCCED";
    string word2 = "SEE";
    string word3 = "ABCB";

    cout << "Word 'ABCCED' exists? " << (sol.exist(board, word1) ? "Yes" : "No") << endl;
    cout << "Word 'SEE' exists? " << (sol.exist(board, word2) ? "Yes" : "No") << endl;
    cout << "Word 'ABCB' exists? " << (sol.exist(board, word3) ? "Yes" : "No") << endl;

    cout << "Word 'ABCCED' exists? " << (sol2.exist(board, word1) ? "Yes" : "No") << endl;
    cout << "Word 'SEE' exists? " << (sol2.exist(board, word2) ? "Yes" : "No") << endl;
    cout << "Word 'ABCB' exists? " << (sol2.exist(board, word3) ? "Yes" : "No") << endl;

    return 0;
}
