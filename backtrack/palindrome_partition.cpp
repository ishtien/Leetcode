#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        vector<vector<string>> res;
        backtrack(s, cur, res);
        return res;
    }

    void backtrack(string s, vector<string>& cur, vector<vector<string>>& res) {
        if (s.size() == 0) {
            res.push_back(cur);
            return;
        }
        for (int i = 1; i <= s.size(); i++) {
            string sub1 = s.substr(0, i);
            string sub2 = "";
            if (i != s.size()) sub2 = s.substr(i, s.size() - i);
            if (isPalindrome(sub1)) {
                cur.push_back(sub1);
                backtrack(sub2, cur, res);
                cur.pop_back();
            }
        }
    }

    bool isPalindrome(string s) {
        if (s.size() <= 1) return true;
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    Solution sol;
    string s = "aab";
    vector<vector<string>> result = sol.partition(s);

    // Print the result
    cout << "Palindrome Partitionings of \"" << s << "\":" << endl;
    for (const auto& partition : result) {
        cout << "[";
        for (const auto& str : partition) {
            cout << "\"" << str << "\" ";
        }
        cout << "]" << endl;
    }

    return 0;
}
