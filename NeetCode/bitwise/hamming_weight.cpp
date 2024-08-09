#include <iostream>
#include <cstdint>
using namespace std;

class SolutionModify {
public:
    int hammingWeight(uint32_t n) {
        // 1001  -> 100 -> 10 -> 1 -> 0
        int res = 0;
        while( n != 0) {
            res += n & 1;
            n >>=1;
        }
        return res;

    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        // 1001 & 1000 -> 1000
        // 1000 & 0111 -> 0000
        int res = 0;
        while (n != 0) {
            n = n & (n - 1);
            res++;
        }
        return res;
    }
};

int main() {
    Solution sol;
    

    // Test case 1
    uint32_t num1 = 9; // Binary: 1001
    cout << "Hamming weight of " << num1 << " is: " << sol.hammingWeight(num1) << endl; // Output: 2

    // Test case 2
    uint32_t num2 = 15; // Binary: 1111
    cout << "Hamming weight of " << num2 << " is: " << sol.hammingWeight(num2) << endl; // Output: 4

    // Test case 3
    uint32_t num3 = 0; // Binary: 0
    cout << "Hamming weight of " << num3 << " is: " << sol.hammingWeight(num3) << endl; // Output: 0

    // Test case 4
    uint32_t num4 = 255; // Binary: 11111111
    cout << "Hamming weight of " << num4 << " is: " << sol.hammingWeight(num4) << endl; // Output: 8

    return 0;
}
