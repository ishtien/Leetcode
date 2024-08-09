#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        int res_len = 0;
        for (int i = 0; i < s.size(); i++) {
            int l = i;
            int r = i;
            isPalindrome(s, l, r, res, res_len);
            
            if(i < s.size() - 1) {
                l = i;
                r = i + 1;
                isPalindrome(s, l, r, res, res_len);
            }

        }
        return res;
    }
    void isPalindrome(string & s, int& l, int& r, string & res, int& res_len) {
        while(l >=0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        if(r - l - 1 > res_len) {
            res_len = r - l - 1 ;
            res = s.substr(l + 1, res_len);
        }
        return;
    }
};


int main() {
    Solution sol;
    string input = "babad";
    string result = sol.longestPalindrome(input);
    
    cout << "Input: " << input << endl;
    cout << "Longest Palindrome: " << result << endl;
    
    return 0;
}
