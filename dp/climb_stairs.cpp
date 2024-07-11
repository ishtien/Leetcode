#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        int prev_1 = 1;
        int prev_2 = 2;
        int result = 0;
        
        for (int i = 3; i <= n; i++) {
            result = prev_1 + prev_2;
            prev_1 = prev_2;
            prev_2 = result;
        }
        
        return result;
    }
};

int main() {
    Solution sol;

    int n1 = 2;
    int n2 = 3;
    int n3 = 5;
    
    cout << "Number of ways to climb stairs for n1 = " << n1 << ": " << sol.climbStairs(n1) << endl;
    cout << "Number of ways to climb stairs for n2 = " << n2 << ": " << sol.climbStairs(n2) << endl;
    cout << "Number of ways to climb stairs for n3 = " << n3 << ": " << sol.climbStairs(n3) << endl;
}