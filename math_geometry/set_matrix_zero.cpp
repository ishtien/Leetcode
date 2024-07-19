#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class SolutionModify {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        bool row_zero = false;
        for(int i = 0; i < rows; i++) {
            for(int j = 0;j < cols; j++) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    if(i == 0 && matrix[i][j] == 0) row_zero =true;
                    else matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < rows; i++) {
            if(matrix[i][0] == 0) {
                for(int j = 0; j < cols; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int i = 0; i < cols; i++) {
            if(matrix[0][i] == 0) {
                for(int j = 0; j < rows; j++) {
                    matrix[j][i] = 0;
                }
            }
        }
        if(row_zero == true) {
            for(int i = 0; i < cols; i++) {
                matrix[0][i] = 0;
            }
        }
        
    }
};

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> row_with_0;
        unordered_set<int> col_with_0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(matrix[i][j] == 0) {
                    row_with_0.insert(i);
                    col_with_0.insert(j);
                }
            }
        }
        for(auto &row: row_with_0) {
            for(int i = 0; i < cols; i++) {
                matrix[row][i] = 0;
            }
        }
        for(auto &col: col_with_0) {
            for(int i = 0; i < rows; i++) {
                matrix[i][col] = 0;
            }
        }
    }
};

void printMatrix(const vector<vector<int>>& matrix) {
    for(const auto& row : matrix) {
        for(const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example usage:
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 0, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 0}
    };
    
    cout << "Original matrix:" << endl;
    printMatrix(matrix);
    
    Solution sol;
    sol.setZeroes(matrix);
    
    cout << "Matrix after setZeroes:" << endl;
    printMatrix(matrix);
    
    return 0;
}
