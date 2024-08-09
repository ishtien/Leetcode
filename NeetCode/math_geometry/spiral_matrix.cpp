#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty()) return res;
        int left = 0;
        int right = matrix[0].size();
        int top = 0;
        int bottom = matrix.size();
        
        while(left != right && top != bottom) {
            for(int i = left; i < right; i++) {
                res.push_back(matrix[top][i]);
            }
            top++;
            for(int i = top; i < bottom; i++) {
                res.push_back(matrix[i][right-1]);
            }
            right--;
            if(!(left < right && top < bottom))break;
            for(int i = right - 1; i >=left; i--) {
                res.push_back(matrix[bottom-1][i]);
            }
            bottom--;
            for(int i = bottom - 1; i>=top; i--) {
                res.push_back(matrix[i][left]);
            }
            left++;
        }
        return res;
    }
};


int main() {
    Solution sol;
    
    // Test case 1: A 3x3 matrix
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<int> result1 = sol.spiralOrder(matrix1);
    cout << "Spiral Order of matrix1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 2: A 4x3 matrix
    vector<vector<int>> matrix2 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    };
    vector<int> result2 = sol.spiralOrder(matrix2);
    cout << "Spiral Order of matrix2: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 3: A 2x4 matrix
    vector<vector<int>> matrix3 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8}
    };
    vector<int> result3 = sol.spiralOrder(matrix3);
    cout << "Spiral Order of matrix3: ";
    for (int num : result3) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 4: A 1x1 matrix
    vector<vector<int>> matrix4 = {
        {1}
    };
    vector<int> result4 = sol.spiralOrder(matrix4);
    cout << "Spiral Order of matrix4: ";
    for (int num : result4) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 5: An empty matrix
    vector<vector<int>> matrix5 = {};
    vector<int> result5 = sol.spiralOrder(matrix5);
    cout << "Spiral Order of matrix5: ";
    for (int num : result5) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
