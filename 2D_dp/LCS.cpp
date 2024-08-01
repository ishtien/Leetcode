#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int sz1 = text1.size();
        int sz2 = text2.size();
        vector<vector<int>> dp(sz1 + 1, vector<int>(sz2 + 1, 0));
        for(int i = sz1 - 1; i >=0; i--) {
            for(int j = sz2 - 1; j >=0 ; j--) {
                if(text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i+1][j+1];
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};

int main() {
    Solution sol;

    string text1 = "abcde";
    string text2 = "ace";

    cout << "Longest Common Subsequence length: " << sol.longestCommonSubsequence(text1, text2) << endl;

    return 0;
}
