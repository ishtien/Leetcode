#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1);
        dp[s.size()] = 1;
        
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
            } else {
                dp[i] = dp[i + 1];
                if (i + 1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
                    dp[i] += dp[i + 2];
                }
            }
        }
        
        return dp[0];
    }
};

int main() {
    Solution sol;

    // Test cases
    string input1 = "12";
    string input2 = "226";
    string input3 = "0";
    string input4 = "06";
    string input5 = "10";

    cout << "Input: " << input1 << " => Number of ways to decode: " << sol.numDecodings(input1) << endl;
    cout << "Input: " << input2 << " => Number of ways to decode: " << sol.numDecodings(input2) << endl;
    cout << "Input: " << input3 << " => Number of ways to decode: " << sol.numDecodings(input3) << endl;
    cout << "Input: " << input4 << " => Number of ways to decode: " << sol.numDecodings(input4) << endl;
    cout << "Input: " << input5 << " => Number of ways to decode: " << sol.numDecodings(input5) << endl;

    return 0;
}
