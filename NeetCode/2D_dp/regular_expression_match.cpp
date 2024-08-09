#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        unordered_map<long, int> cache;
        return dfs(s, p, cache, 0, 0);
        
    }
    bool dfs(string s, string p, unordered_map<long, int>& cache, int i, int j) {
        if(i >= s.size() && j >=p.size()) return true;
        if(j >= p.size()) return false;
        long key = (static_cast<long>(i) << 32) | j;
        if(cache.find(key) != cache.end()) return cache[key];
        bool match = false;
        if(i < s.size() && (s[i] == p[j] || p[j] == '.')) {
            match = dfs(s, p, cache, i + 1, j + 1);
        }
        if(j + 1 < p.size() && p[j+1] == '*') {
            if(i < s.size() && (s[i] == p[j] || p[j] == '.')) {
                match = dfs(s, p, cache, i + 1, j) || dfs(s, p, cache, i, j + 2);
            } else {
                match = dfs(s, p, cache, i, j + 2);
            }
        }
        cache[key] = match;
        return match;
    }
};


int main() {
    Solution sol;
    
    // Test cases
    cout << sol.isMatch("aa", "a") << endl;        // false
    cout << sol.isMatch("aa", "a*") << endl;       // true
    cout << sol.isMatch("ab", ".*") << endl;       // true
    cout << sol.isMatch("aab", "c*a*b") << endl;   // true
    cout << sol.isMatch("mississippi", "mis*is*p*.") << endl;  // false
    
    return 0;
}
