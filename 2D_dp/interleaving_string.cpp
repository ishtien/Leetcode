#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int sz1 = s1.size();
        int sz2 = s2.size();
        int sz3 = s3.size();
        if ((sz1 + sz2) != sz3) return false;
        
        vector<vector<bool>> dp(sz1 + 1, vector<bool>(sz2 + 1, false));
        dp[sz1][sz2] = true;
        
        for (int i = sz1; i >= 0; i--) {
            for (int j = sz2; j >= 0; j--) {
                if (i < sz1 && s1[i] == s3[i + j] && dp[i + 1][j] == true)
                    dp[i][j] = true;
                if (j < sz2 && s2[j] == s3[i + j] && dp[i][j + 1] == true)
                    dp[i][j] = true;
            }
        }

        return dp[0][0];
    }
};

class SolutionRecursive {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        unordered_map<long, bool> memo;
        return dfs(0, 0, s1, s2, s3, memo);
    }
    bool dfs(int i, int j, string s1, string s2, string s3, unordered_map<long, bool> &memo) {
        long key = static_cast<long> (i) << 32 | j;
        bool res = false;
        if(memo.find(key) != memo.end()) return memo[key];
        if(i == s1.size() && j == s2.size()) return true;
        if(i < s1.size() && s3[i + j] == s1[i]) {
            res = dfs(i+1, j, s1, s2, s3, memo);
        }
        if(!res && j < s2.size() && s3[i + j] == s2[j]){
            res = dfs(i, j + 1, s1, s2, s3, memo);
        }
        memo[key] = res;
        return memo[key];
    }
};

int main() {
    Solution solution;
    SolutionRecursive solution_recursive;

    // Test case 1
    string s1_1 = "aabcc";
    string s2_1 = "dbbca";
    string s3_1 = "aadbbcbcac";
    cout << "Test case 1: " << (solution.isInterleave(s1_1, s2_1, s3_1) ? "true" : "false") << endl;

    // Test case 2
    string s1_2 = "aabcc";
    string s2_2 = "dbbca";
    string s3_2 = "aadbbbaccc";
    cout << "Test case 2: " << (solution.isInterleave(s1_2, s2_2, s3_2) ? "true" : "false") << endl;

    // Test case 3
    string s1_3 = "abc";
    string s2_3 = "def";
    string s3_3 = "adbcef";
    cout << "Test case 3: " << (solution.isInterleave(s1_3, s2_3, s3_3) ? "true" : "false") << endl;

    // Test case 4
    string s1_4 = "";
    string s2_4 = "";
    string s3_4 = "";
    cout << "Test case 4: " << (solution.isInterleave(s1_4, s2_4, s3_4) ? "true" : "false") << endl;

    // Test case 5
    string s1_5 = "a";
    string s2_5 = "b";
    string s3_5 = "ab";
    cout << "Test case 5: " << (solution.isInterleave(s1_5, s2_5, s3_5) ? "true" : "false") << endl;


    cout << endl;

    cout << "Test case 1: " << (solution_recursive.isInterleave(s1_1, s2_1, s3_1) ? "true" : "false") << endl;
    cout << "Test case 2: " << (solution_recursive.isInterleave(s1_2, s2_2, s3_2) ? "true" : "false") << endl;
    cout << "Test case 3: " << (solution_recursive.isInterleave(s1_3, s2_3, s3_3) ? "true" : "false") << endl;
    cout << "Test case 4: " << (solution_recursive.isInterleave(s1_4, s2_4, s3_4) ? "true" : "false") << endl;
    cout << "Test case 5: " << (solution_recursive.isInterleave(s1_5, s2_5, s3_5) ? "true" : "false") << endl;

    return 0;
}
