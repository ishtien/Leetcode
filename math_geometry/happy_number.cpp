#include <iostream>
#include <unordered_set>
#include <cmath> // For pow function

using namespace std;

class SolutionModify {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = sumSquareDigits(n);
        while(slow != fast) {
            fast = sumSquareDigits(sumSquareDigits(fast));
            slow = sumSquareDigits(slow);
        }
        return (slow==1)?true: false;
        
    }
private:
    int sumSquareDigits(int n) {
        int res = 0;
        while(n > 0) {
            res += pow(n%10, 2);
            n /= 10;
        }
        return res;
    }
};

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> happy;
        int res = 0;
        while (res != 1) {
            res = 0;
            while (n > 0) {
                res += pow(n % 10, 2);
                n /= 10;
            }
            n = res;
            if (happy.find(res) != happy.end()) return false;
            happy.insert(res);
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Test cases
    int num1 = 19;
    int num2 = 20;

    cout << "Is " << num1 << " a happy number? " << (sol.isHappy(num1) ? "Yes" : "No") << endl;
    cout << "Is " << num2 << " a happy number? " << (sol.isHappy(num2) ? "Yes" : "No") << endl;

    return 0;
}
