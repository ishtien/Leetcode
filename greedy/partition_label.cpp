#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class SolutionModify {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> hmap;
        vector<int> res;
        int cur = 0;
        int goal = 0;
        for(int i = 0; i < s.size(); i++) {
            hmap[s[i]]= i;
        }
        for(int i = 0; i < s.size(); i++) {
            goal = max(goal, hmap[s[i]]);
            cur++;
            if(goal == i) {
                res.push_back(cur);
                cur = 0;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int, int> hmap;
        unordered_set<int> myset;
        vector<int> res;
        int cur = 0;

        for(auto &ch : s) {
            hmap[ch]++;
        }

        for(int i = 0; i < s.size(); i++) {
            myset.insert(s[i]);
            hmap[s[i]]--;
            cur++;
            if(hmap[s[i]] == 0) myset.erase(s[i]);
            if(myset.empty()) {
                res.push_back(cur);
                cur = 0;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Test case 1
    string s1 = "abac";
    vector<int> result1 = sol.partitionLabels(s1);
    cout << "Partition labels for '" << s1 << "': ";
    for (int label : result1) {
        cout << label << " ";
    }
    cout << endl; // Output: Partition labels for 'abac': 3 1

    // Test case 2
    string s2 = "abcdefg";
    vector<int> result2 = sol.partitionLabels(s2);
    cout << "Partition labels for '" << s2 << "': ";
    for (int label : result2) {
        cout << label << " ";
    }
    cout << endl; // Output: Partition labels for 'abcdefg': 1 1 1 1 1 1 1

    return 0;
}
