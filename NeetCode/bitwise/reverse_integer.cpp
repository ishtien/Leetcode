#include <iostream>
#include <limits> // for INT_MIN and INT_MAX
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int MIN = INT_MIN;
        int MAX = INT_MAX;
        int res = 0;
        int digit = 0;
        while(x != 0) {
            digit = x % 10;
            x = x / 10;

            if(res > MAX/10 || (res == MAX/10 && digit > MAX%10)) return 0;
            if(res < MIN/10 || (res == MIN/10 && digit < MIN%10)) return 0;
            
            res = res * 10 + digit;
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Test cases
    int x1 = 123;
    cout << "Reverse of " << x1 << ": " << sol.reverse(x1) << endl; // Expected output: 321

    int x2 = -123;
    cout << "Reverse of " << x2 << ": " << sol.reverse(x2) << endl; // Expected output: -321

    int x3 = 120;
    cout << "Reverse of " << x3 << ": " << sol.reverse(x3) << endl; // Expected output: 21

    int x4 = 1534236469;
    cout << "Reverse of " << x4 << ": " << sol.reverse(x4) << endl; // Expected output: 0 (overflow case)

    return 0;
}
