#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int sz1 = s.size();
        int sz2 = t.size();
        vector<vector<int>> cache(sz1, vector<int>(sz2, 0));
        helper(0, 0, s, t, cache);
        return cache[0][0];
        
    }
    int helper(int i, int j, string s, string t, vector<vector<int>> & cache) {
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;
        if(cache[i][j] != 0) return cache[i][j];
        if(s[i] == t[j]) {
            cache[i][j] = helper(i + 1, j + 1, s, t, cache) + helper(i + 1, j , s, t, cache);
        } else {
            cache[i][j] = helper(i + 1, j, s, t, cache);
        }
        return cache[i][j];
    }
};


int main() {
    Solution solution;

    // Test case 1
    string s1 = "rabbbit";
    string t1 = "rabbit";
    cout << "Test case 1: " << solution.numDistinct(s1, t1) << endl;

    // Test case 2
    string s2 = "babgbag";
    string t2 = "bag";
    cout << "Test case 2: " << solution.numDistinct(s2, t2) << endl;

    // Test case 3
    string s3 = "aaaaa";
    string t3 = "aaa";
    cout << "Test case 3: " << solution.numDistinct(s3, t3) << endl;

    // Test case 4
    string s4 = "a";
    string t4 = "a";
    cout << "Test case 4: " << solution.numDistinct(s4, t4) << endl;

    // Test case 5
    string s5 = "a";
    string t5 = "b";
    cout << "Test case 5: " << solution.numDistinct(s5, t5) << endl;

    return 0;
}
