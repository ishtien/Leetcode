#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[s.size()] = true;
        for (int i = s.size() - 1; i >= 0; i--) {
            for (auto &w : wordDict) {
                if (i + w.size() <= s.size()) {
                    string tmp = s.substr(i, w.size());
                    if (tmp == w) dp[i] = dp[i + w.size()];
                    if (dp[i] == true) break;
                }
            }
        }
        return dp[0];
    }
};

int main() {
    Solution sol;

    // Example 1
    string s1 = "leetcode";
    vector<string> wordDict1 = {"leet", "code"};
    cout << "Can \"" << s1 << "\" be segmented? " << (sol.wordBreak(s1, wordDict1) ? "Yes" : "No") << endl;

    // Example 2
    string s2 = "applepenapple";
    vector<string> wordDict2 = {"apple", "pen"};
    cout << "Can \"" << s2 << "\" be segmented? " << (sol.wordBreak(s2, wordDict2) ? "Yes" : "No") << endl;

    // Example 3
    string s3 = "catsandog";
    vector<string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};
    cout << "Can \"" << s3 << "\" be segmented? " << (sol.wordBreak(s3, wordDict3) ? "Yes" : "No") << endl;

    return 0;
}
