#include <iostream>
using namespace std;

class SolutionModify {
public:
    int add(int carry, int xorRes) {
        if(carry == 0 || xorRes ==0 ) return xorRes | carry;
        return add((carry&xorRes) << 1, carry^xorRes);
    }
    int getSum(int a, int b) {
        return add(a, b);
    }
};

class SolutionModifyWhile {
public:
    int getSum(int a, int b) {
        int xorRes = a^b;
        int carry = (a&b) << 1;
        
        while(carry) {
            int temp = xorRes;
            xorRes = carry^xorRes;
            carry = (carry&temp) << 1;
        }
        return xorRes;
    }
};


class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int a_cur = a & (1 << i);
            int b_cur = b & (1 << i);
            int carry_bit = carry << i;  // Corrected variable name to avoid conflict
            int current = a_cur ^ b_cur ^ carry_bit;
            res += current;
            if ((a_cur & b_cur) || (a_cur & carry_bit) || (b_cur & carry_bit)) {
                carry = 1;
            } else {
                carry = 0;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Test case 1
    int a1 = 1, b1 = 2;
    cout << "Sum of " << a1 << " and " << b1 << ": " << sol.getSum(a1, b1) << endl; // Output: 3

    // Test case 2
    int a2 = -2, b2 = 3;
    cout << "Sum of " << a2 << " and " << b2 << ": " << sol.getSum(a2, b2) << endl; // Output: 1

    // Test case 3
    int a3 = -10, b3 = -20;
    cout << "Sum of " << a3 << " and " << b3 << ": " << sol.getSum(a3, b3) << endl; // Output: -30

    return 0;
}
