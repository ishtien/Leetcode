#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int leftmax = 0;
        int leftmin = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                leftmax++;
                leftmin++;
            } else if (s[i] == ')') {
                leftmax--;
                leftmin--;
            } else if (s[i] == '*') {
                leftmax++;
                leftmin--;
            }
            if (leftmax < 0) return false;
            if (leftmin < 0) leftmin = 0;
        }
        return leftmin == 0;
    }
};

int main() {
    Solution sol;

    // Test case 1
    string s1 = "()";
    cout << "Is valid string for '" << s1 << "': " << sol.checkValidString(s1) << endl; // Output: Is valid string for '()': 1 (true)

    // Test case 2
    string s2 = "(*)";
    cout << "Is valid string for '" << s2 << "': " << sol.checkValidString(s2) << endl; // Output: Is valid string for '(*)': 1 (true)

    // Test case 3
    string s3 = "(*))";
    cout << "Is valid string for '" << s3 << "': " << sol.checkValidString(s3) << endl; // Output: Is valid string for '(*))': 1 (true)

    // Test case 4
    string s4 = "(((******))";
    cout << "Is valid string for '" << s4 << "': " << sol.checkValidString(s4) << endl; // Output: Is valid string for '(((******))': 1 (true)

    // Test case 5
    string s5 = "(*()";
    cout << "Is valid string for '" << s5 << "': " << sol.checkValidString(s5) << endl; // Output: Is valid string for '(*()': 1 (true)

    // Test case 6
    string s6 = "())";
    cout << "Is valid string for '" << s6 << "': " << sol.checkValidString(s6) << endl; // Output: Is valid string for '())': 0 (false)

    return 0;
}
