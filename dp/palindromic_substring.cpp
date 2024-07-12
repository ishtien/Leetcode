#include <iostream>
#include <vector>
#include <string>

using namespace std;

class SolutionModify {
public:
    int countSubstrings(string s) {
        int res = 0;
        for(int i = 0; i < s.size(); i++) {
            int l = i;
            int r = i;
            res += checkPalindrome(l, r, s);
            if(i < s.size() - 1) {
                l = i;
                r = i + 1;
                res += checkPalindrome(l, r, s);
            }
        }
        return res;
    }
    int checkPalindrome(int & l, int & r, string &s) {
        int res = 0;
        while(l >= 0 && r < s.size() && s[l] == s[r]) {
            res ++;
            l --;
            r ++;
        }
        return res;   
    }
};

class Solution {
public:
    int countSubstrings(string s) {
        vector<string> res;
        for(int i = 0; i < s.size(); i++) {
            int l = i;
            int r = i;
            checkPalindrome(l, r, s, res);
            if(i < s.size() - 1) {
                l = i;
                r = i + 1;
                checkPalindrome(l, r, s, res);
            }
        }
        return res.size();
    }
    void checkPalindrome(int & l, int & r, string &s, vector<string> &res) {
        while(l >= 0 && r < s.size() && s[l] == s[r]) {
            string str = s.substr(l, r - l + 1);
            res.push_back(str);
            l --;
            r ++;
        }
        
    }
};


int main() {
    Solution sol;
    SolutionModify sol2;

    // Test cases
    string input1 = "abc";
    string input2 = "aaa";
    string input3 = "aba";
    string input4 = "abba";

    cout << "Input: " << input1 << " => Number of palindromic substrings: " << sol.countSubstrings(input1) << endl;
    cout << "Input: " << input2 << " => Number of palindromic substrings: " << sol.countSubstrings(input2) << endl;
    cout << "Input: " << input3 << " => Number of palindromic substrings: " << sol.countSubstrings(input3) << endl;
    cout << "Input: " << input4 << " => Number of palindromic substrings: " << sol.countSubstrings(input4) << endl;

    cout << "Input: " << input1 << " => Number of palindromic substrings: " << sol2.countSubstrings(input1) << endl;
    cout << "Input: " << input2 << " => Number of palindromic substrings: " << sol2.countSubstrings(input2) << endl;
    cout << "Input: " << input3 << " => Number of palindromic substrings: " << sol2.countSubstrings(input3) << endl;
    cout << "Input: " << input4 << " => Number of palindromic substrings: " << sol2.countSubstrings(input4) << endl;
    return 0;
}
