#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cur;
        vector<vector<int>> res;
        int total = 0;

        sort(candidates.begin(), candidates.end());
        helper(0, candidates, target, total, cur, res);
        return res;
    }

    void helper(int idx, vector<int>& candidates, int& target, int& total, vector<int>& cur, vector<vector<int>>& res) {
        if(total == target) {
            res.push_back(cur);
            return;
        }
        if(idx >= candidates.size() || total > target) return;
        for(int i = idx; i < candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i-1]) continue;
            total += candidates[i];
            cur.push_back(candidates[i]);
            helper(i + 1, candidates, target, total, cur, res);
            total -= candidates[i];
            cur.pop_back();
        }
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {1, 2, 2, 3};
    int target = 4;
    vector<vector<int>> result = sol.combinationSum2(candidates, target);

    // Print the result
    cout << "Result:" << endl;
    for (const auto& combination : result) {
        cout << "[";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
