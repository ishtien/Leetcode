#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j ++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    Solution sol;
    int m, n;
    
    // Example 1
    m = 3;
    n = 7;
    cout << "For m = " << m << ", n = " << n << ", unique paths = " << sol.uniquePaths(m, n) << endl;
    
    // Example 2
    m = 3;
    n = 2;
    cout << "For m = " << m << ", n = " << n << ", unique paths = " << sol.uniquePaths(m, n) << endl;
    
    // Example 3
    m = 7;
    n = 3;
    cout << "For m = " << m << ", n = " << n << ", unique paths = " << sol.uniquePaths(m, n) << endl;
    
    return 0;
}
