#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int sz = matrix.size() - 1;
        int left = 0;
        int right = sz;
        int top = 0;
        int bottom = sz;
        while(left < right) {
            for(int i = 0; i < right - left; i++) {
                int left_top = matrix[top][left + i];
                int right_top = matrix[top + i][right];
                int right_bottom = matrix[bottom][right - i];
                int left_bottom = matrix[bottom - i][left];
                matrix[top][left + i] = left_bottom;
                matrix[top + i][right] = left_top;
                matrix[bottom][right - i] = right_top;
                matrix[bottom - i][left] = right_bottom;
            }
            left++;
            right--;
            top++;
            bottom--;
        }
    }
};

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution sol;

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    sol.rotate(matrix);

    cout << "\nRotated Matrix:" << endl;
    printMatrix(matrix);

    return 0;
}
