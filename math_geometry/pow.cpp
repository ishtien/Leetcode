#include <iostream>
#include <iomanip> // For setting precision

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double res = helper(x, n);
        return (n>1)? res : 1/res;
    }
    double helper(double x, int n) {
        if(n == 0) return 1;
        if(x == 0) return 0;
        double half = helper(x, n/2);
        return (n%2 == 0)? half*half : x*half*half;
    }
};


int main() {
    Solution sol;

    // Test case 1: Positive exponent
    double x1 = 2.0;
    int n1 = 10;
    cout << "x = " << x1 << ", n = " << n1 << " => x^n = " << fixed << setprecision(6) << sol.myPow(x1, n1) << endl;

    // Test case 2: Negative exponent
    double x2 = 2.0;
    int n2 = -3;
    cout << "x = " << x2 << ", n = " << n2 << " => x^n = " << fixed << setprecision(6) << sol.myPow(x2, n2) << endl;

    // Test case 3: Zero base with positive exponent
    double x3 = 0.0;
    int n3 = 5;
    cout << "x = " << x3 << ", n = " << n3 << " => x^n = " << fixed << setprecision(6) << sol.myPow(x3, n3) << endl;

    // Test case 4: Zero base with zero exponent
    double x4 = 0.0;
    int n4 = 0;
    cout << "x = " << x4 << ", n = " << n4 << " => x^n = " << fixed << setprecision(6) << sol.myPow(x4, n4) << endl;

    // Test case 5: Base of 1
    double x5 = 1.0;
    int n5 = 100;
    cout << "x = " << x5 << ", n = " << n5 << " => x^n = " << fixed << setprecision(6) << sol.myPow(x5, n5) << endl;

    // Test case 6: Negative base with odd exponent
    double x6 = -2.0;
    int n6 = 3;
    cout << "x = " << x6 << ", n = " << n6 << " => x^n = " << fixed << setprecision(6) << sol.myPow(x6, n6) << endl;

    return 0;
}
