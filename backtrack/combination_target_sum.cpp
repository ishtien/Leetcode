#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        vector<vector<int>> res;
        int total = 0;
        int idx = 0;
        helper(idx, nums, target, total, cur, res);
        return res;
    }
    
    void helper(int idx, vector<int>& nums, int target, int total, vector<int>& cur, vector<vector<int>>& res) {
        if(total > target || idx >= nums.size()) {
            return;
        } else if(total == target) {
            res.push_back(cur);
            return;
        } 
        cur.push_back(nums[idx]);
        total += nums[idx];
        helper(idx, nums, target, total, cur, res);
        cur.pop_back();
        total -= nums[idx];
        helper(idx + 1, nums, target, total, cur, res);
    } 
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 6, 7}; // Example input
    int target = 7; // Example target

    vector<vector<int>> result = sol.combinationSum(nums, target);

    // Print the result
    cout << "All combinations that sum up to " << target << ":" << endl;
    for (const auto& combination : result) {
        cout << "[";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
