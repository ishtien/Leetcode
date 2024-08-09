#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, string> map = {
        {2 , "abc"},
        {3 , "def"},
        {4 , "ghi"},
        {5 , "jkl"},
        {6 , "mno"},
        {7 , "pqrs"},
        {8 , "tuv"},
        {9 , "wxyz"}
    };

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        string cur = "";
        backtrack(digits, 0, cur, res);
        return res;
    }

    void backtrack(string digits, int idx, string cur, vector<string>& res) {
        if (idx == digits.size()) {
            res.push_back(cur);
            return;
        }
        int digit = digits[idx] - '0';
        for (char c : map[digit]) {
            cur += c;
            backtrack(digits, idx + 1, cur, res);
            cur.pop_back();
        }
    }
};

int main() {
    Solution sol;
    string digits = "23";
    vector<string> result = sol.letterCombinations(digits);

    // Print the result
    cout << "Letter Combinations for \"" << digits << "\":" << endl;
    for (const string& comb : result) {
        cout << comb << " ";
    }
    cout << endl;

    return 0;
}
