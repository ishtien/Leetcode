#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        vector<bool> used(nums.size(), false);
        helper(nums, cur, res, used);
        return res;
    }
    void helper(vector<int>& nums, vector<int>& cur, vector<vector<int>>& res, vector<bool>& used) {
        if(nums.size() == cur.size()) {
            res.push_back(cur);
            return;
        }

        for(int i = 0 ; i < nums.size(); i++) {
            if(used[i] == true) {
                continue;
            } else {
                cur.push_back(nums[i]);
                used[i] = true;
                helper(nums, cur, res, used);
                cur.pop_back();
                used[i] = false;
            }
        }
        
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3}; // Example input

    vector<vector<int>> result = sol.permute(nums);

    // Print the result
    cout << "All permutations:" << endl;
    for (const auto& permutation : result) {
        cout << "[";
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
