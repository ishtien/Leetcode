#include <iostream>
#include <cstdint> // for uint32_t
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
            res <<= 1;
            res += n & 1;
            n >>= 1;
        }
        return res;
    }
};

class SolutionModify {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i = 0; i < 32; i++) {
            res += ((n >> i)& 1) << (31 - i);
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Test case 1
    uint32_t num1 = 43261596; // Binary: 00000010100101000001111010011100
    uint32_t reversed1 = sol.reverseBits(num1);
    cout << "Reversed bits of " << num1 << " is: " << reversed1 << endl; // Output: Reversed bits of 43261596 is: 964176192

    // Test case 2
    uint32_t num2 = 4294967293; // Binary: 11111111111111111111111111111101
    uint32_t reversed2 = sol.reverseBits(num2);
    cout << "Reversed bits of " << num2 << " is: " << reversed2 << endl; // Output: Reversed bits of 4294967293 is: 3221225471

    // Test case 3
    uint32_t num3 = 1; // Binary: 00000000000000000000000000000001
    uint32_t reversed3 = sol.reverseBits(num3);
    cout << "Reversed bits of " << num3 << " is: " << reversed3 << endl; // Output: Reversed bits of 1 is: 2147483648

    return 0;
}
